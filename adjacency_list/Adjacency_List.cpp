#include"Adjacency_List.h"
#include"Priority_Queue.h"
#include"Stack.cpp"

enum number { infinity = INT_MAX, NIL = -1 }; // enum�� ����Ͽ� ���Ǵ�Ƽ�� �� ���� ����
void Adjacency_List::DIJKSTRA(vector<int>& v, int size)
{
	Priority_Queue Q;

	INITIALIZE_SINGLE_SOURCE(size); // d,pi,w�� �ʱ�ȭ ����
	Q.Get_List(size); // Queue�� ����� ���� size�� ������ Queue vector�� ����

	for (int i = 0; i < size-1;i++) {
		Node* p = G->head;
		int u = Q.Heap_Extract_Min(G->head); 
		while (p != NULL) { // ��� ���� ���� ���ؼ� while�� ���
			if (p->start == u) { // �ּڰ� u�� Node�� start�� ���� ������ ����
				w[p->edge] = p->vertex; // Relex �Լ��� ���� �������� �ʰ� ������.
				if (d[p->edge] > w[p->edge] + d[u]) {
					d[p->edge] = w[p->edge] + d[u];
					pi[p->edge] = u;
					Q.Heap_Decrease_Key(p->edge, d[p->edge]);
				}
			}
			p = p->link;

		}		
	}

	Output();
}
void Adjacency_List::ApendTerm(List* input, int vertex, int edge, int start, Node* last) { //��忡 �����ϴ� �Լ�
	Node* node = new Node; //���ο� ��� ����
	node->start = start;
	node->edge = edge;
	node->vertex = vertex;
	node->link = NULL;

	if (input->head == NULL) { //��尡 ��������� ���ο� ��� �߰�
		input->head = node;
		last = node;
	}
	else { //�̹� ���� ���� �����ߴٸ� �̾ ���� �߰�
		last = input->head;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = node;
	}


}
void Adjacency_List::INITIALIZE_SINGLE_SOURCE(int size)
{
	for (int i = 0; i < size ; i++) // d�� ����, w�� 0, pi�� -1�� �ʱ�ȭ�� �� d[0]���� 0���� ����
	{
		d.push_back(infinity);
		pi.push_back(NIL);
		w.push_back(0);
	}
	d[0] = 0;
}


void Adjacency_List::Make_List(vector<int>& v, int size) //main������ ���� vector�� size�� Ȱ���Ͽ� ����Ʈ�� ������. ���Ḯ��Ʈ�� appendterm�� Ȱ��
{
	G = new List;
	G->head = NULL;
	int S = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i % size == 0 && i > 0)
			S++;
		if (v[i] != 0) { // �ϳ��� ���Ḯ��Ʈ�� ������ ������ ������������ Node�� ������
			ApendTerm(G, v[i], i % size, S, r);
		}
	}
	Node* p = G->head;
	int i = 0;
	for (; p; p = p->link) {
		if (p->edge != 0)
			cout << p->start << " TO PATH: (" << p->edge << " , " << p->vertex << ") " << endl;
	}
	cout << endl << "------------------Graph check------------------" << endl;
}

void Adjacency_List::Output()
{
	int a;
	int j = 0;
	Stack<int> stack(pi.size()); //projec1 �� stack class �� Ȱ���Ͽ� �ִܰŸ��� ǥ����
	for (int i = 1; i < d.size(); i++) {
		cout << "PATH TO " << i<<" >> ";
		stack.Push(pi[i]);
		j=i;
		while (pi[j]>0) {
			j = pi[j];
			stack.Push(pi[j]);
		}
		while (!stack.IsEmpty()) { // stack�� ������� ���� Pop
			stack.Pop(a);
			cout << a << " -> ";
		}

		cout <<i<< " : " << d[i] << endl;
	}
}

 
