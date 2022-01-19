#include"Priority_Queue.h"
#include"Adjacency_List.h"

 static int PARENT(int i) { //PARENT , LEFT , RIGHT를 계속 사용하는데 의미전달이 잘안되서 선언
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
		if (Que.size() < 1) //Que의 size가 1보다 작으면 잘못된 것임으로 오류.
			throw string("underflow error!");
	}
	catch (string error)
	{
		cout << error << endl;
		exit(0);
	}
	int min = Que.begin()->edge; // 최솟값을 Que의 첫번째 edge 값으로 저장함. 이미 전에 정렬이 되어있음
	Que[0] = Que[Que.size()-1]; // 마지막 값을 첫번째 인덱스에 저장
	Que.pop_back(); //Que의 사이즈를 줄임
	Min_Heapify(Que, 0, Que.size()-1); // 값이 변경되었기 때문에 재정렬
	return min;
}
void Priority_Queue::Heap_Decrease_Key(int i, int key)
{
	for (int j = 0; j < Que.size(); j++) { // i값을 받아서 Que.edge 와 i 가 같을 경우 i를 재설정하고 그 vertex 값을 구하기 위함
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
	
	Min_Heapify(Que, 0, Que.size()-1); // 재정렬
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
void Priority_Queue::Exchange(int& x, int& y, vector<Node>& A) // 값을 바꾸기 위한 함수
{
	Node p;
	p = A[x];
	A[x] = A[y];
	A[y] = p;
}
void Priority_Queue::Get_List(int size) 
{
	Node q;
	for (int i = 0; i < size; i++) //Vector<Node>Que에 사용할 값들을 초기화 함. i=0일 때는 vertex를 0으로 하고 나머지는 무한으로 초기화
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





