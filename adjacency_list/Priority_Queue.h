#pragma once
#include"Adjacency_List.h"
#include<vector>
#include<stdexcept>
class Priority_Queue {
public:

	int Heap_Extract_Min(Node* g); // 최솟값을 빼내기 위한 함수
	void Heap_Decrease_Key(int i, int key); // key값을 넣어주며 Queue를 계속 최신화 시킴
	void Min_Heapify(vector<Node>& A, int i, int size); // 정렬
	void Exchange(int& x, int& y, vector<Node>& A); // Decrease_key 함수에서 사용하며 값을 바꿔줌
	void Get_List(int size); // Adjancency_List에서 이미 path가 몇개 나올지 알았기 때문에 그 size를 이용해 Queue 생성
	
private:
	vector<Node>Que; // Node형으로 벡터 Que 선언

};