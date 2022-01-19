#include"Adjacency_List.h"
#include"Priority_Queue.h"
#include"Stack.cpp"

enum number { infinity = INT_MAX, NIL = -1 }; // enum을 사용하여 인피니티와 닐 값을 정함
void Adjacency_List::DIJKSTRA(vector<int>& v, int size)
{
	Priority_Queue Q;

	INITIALIZE_SINGLE_SOURCE(size); // d,pi,w를 초기화 해줌
	Q.Get_List(size); // Queue를 만들기 위해 size를 보내서 Queue vector를 생성

	for (int i = 0; i < size-1;i++) {
		Node* p = G->head;
		int u = Q.Heap_Extract_Min(G->head); 
		while (p != NULL) { // 모든 값을 돌기 위해서 while문 사용
			if (p->start == u) { // 최솟값 u를 Node의 start의 값과 같으면 실행
				w[p->edge] = p->vertex; // Relex 함수를 따로 구현하지 않고 실행함.
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
void Adjacency_List::ApendTerm(List* input, int vertex, int edge, int start, Node* last) { //노드에 저장하는 함수
	Node* node = new Node; //새로운 노드 선언
	node->start = start;
	node->edge = edge;
	node->vertex = vertex;
	node->link = NULL;

	if (input->head == NULL) { //헤드가 비어있으면 새로운 노드 추가
		input->head = node;
		last = node;
	}
	else { //이미 전에 값을 저장했다면 이어서 값을 추가
		last = input->head;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = node;
	}


}
void Adjacency_List::INITIALIZE_SINGLE_SOURCE(int size)
{
	for (int i = 0; i < size ; i++) // d는 무한, w는 0, pi는 -1로 초기화한 후 d[0]값만 0으로 지정
	{
		d.push_back(infinity);
		pi.push_back(NIL);
		w.push_back(0);
	}
	d[0] = 0;
}


void Adjacency_List::Make_List(vector<int>& v, int size) //main문에서 받은 vector와 size를 활용하여 리스트에 저장함. 연결리스트의 appendterm을 활용
{
	G = new List;
	G->head = NULL;
	int S = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i % size == 0 && i > 0)
			S++;
		if (v[i] != 0) { // 하나의 연결리스트로 묶었기 때문에 시작지점까지 Node에 저장함
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
	Stack<int> stack(pi.size()); //projec1 의 stack class 를 활용하여 최단거리를 표현함
	for (int i = 1; i < d.size(); i++) {
		cout << "PATH TO " << i<<" >> ";
		stack.Push(pi[i]);
		j=i;
		while (pi[j]>0) {
			j = pi[j];
			stack.Push(pi[j]);
		}
		while (!stack.IsEmpty()) { // stack이 비워질때 까지 Pop
			stack.Pop(a);
			cout << a << " -> ";
		}

		cout <<i<< " : " << d[i] << endl;
	}
}

 
