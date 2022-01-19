#include"Priority_Queue.h"
#include"Adjacency_List.h"

 static int PARENT(int i) { //PARENT , LEFT , RIGHT�� ��� ����ϴµ� �ǹ������� �߾ȵǼ� ����
	return (i-1) / 2;
}
static int LEFT(int i) {
	return (2 * i)+1;
}
static int RIGHT(int i) {
	return (2 * i) +2;
}


int Priority_Queue::Heap_Extract_Min(Node* g)
{
	try
	{
		if (Que.size() < 1) //Que�� size�� 1���� ������ �߸��� �������� ����.
			throw string("underflow error!");
	}
	catch (string error)
	{
		cout << error << endl;
		exit(0);
	}
	int min = Que.begin()->edge; // �ּڰ��� Que�� ù��° edge ������ ������. �̹� ���� ������ �Ǿ�����
	Que[0] = Que[Que.size()-1]; // ������ ���� ù��° �ε����� ����
	Que.pop_back(); //Que�� ����� ����
	Min_Heapify(Que, 0, Que.size()-1); // ���� ����Ǿ��� ������ ������
	return min;
}
void Priority_Queue::Heap_Decrease_Key(int i, int key)
{
	for (int j = 0; j < Que.size(); j++) { // i���� �޾Ƽ� Que.edge �� i �� ���� ��� i�� �缳���ϰ� �� vertex ���� ���ϱ� ����
		if (Que[j].edge == i) {
			i = j;
			break;
		}
	}

	try
	{
		if (key > Que[i].vertex)
			throw string("overflow error!");
	}
	catch (string error)
	{
		cout << error << endl;
		exit(0);
	}
	
	Que[i].vertex = key;
	int parent = PARENT(i);

	while (i > 1 && Que[parent].vertex > Que[i].vertex) {
		Exchange(i, parent, Que);
		i = parent;
	}
	
	Min_Heapify(Que, 0, Que.size()-1); // ������
}

void Priority_Queue::Min_Heapify(vector<Node>& A, int i, int size)
{
	int left = LEFT(i);
	int right = RIGHT(i);
	int min = i;
	Node p;
	if ((left <= size) && (A[left].vertex < A[i].vertex)) { 
		min = left;
	}
	else
		min = i;

	if ((right <= size) && (A[right].vertex < A[min].vertex)) {
		min = right;
	}


	if (min != i) {
		p = A[i];
		A[i] = A[min];
		A[min] = p;
		Min_Heapify(A, min, size);
	}
}
void Priority_Queue::Exchange(int& x, int& y, vector<Node>& A) // ���� �ٲٱ� ���� �Լ�
{
	Node p;
	p = A[x];
	A[x] = A[y];
	A[y] = p;
}
void Priority_Queue::Get_List(int size) 
{
	Node q;
	for (int i = 0; i < size; i++) //Vector<Node>Que�� ����� ������ �ʱ�ȭ ��. i=0�� ���� vertex�� 0���� �ϰ� �������� �������� �ʱ�ȭ
	{
		if (i == 0) {
			q.vertex = 0;
			q.edge = i;
			q.start = 0;
			Que.push_back(q);
		}
		else {
			q.vertex = INT_MAX;
			q.edge = i;
			q.start = 0;
			Que.push_back(q);
		}
	}
}





