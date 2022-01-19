#pragma once
#include"Adjacency_List.h"
#include<vector>
#include<stdexcept>
class Priority_Queue {
public:

	int Heap_Extract_Min(Node* g); // �ּڰ��� ������ ���� �Լ�
	void Heap_Decrease_Key(int i, int key); // key���� �־��ָ� Queue�� ��� �ֽ�ȭ ��Ŵ
	void Min_Heapify(vector<Node>& A, int i, int size); // ����
	void Exchange(int& x, int& y, vector<Node>& A); // Decrease_key �Լ����� ����ϸ� ���� �ٲ���
	void Get_List(int size); // Adjancency_List���� �̹� path�� � ������ �˾ұ� ������ �� size�� �̿��� Queue ����
	
private:
	vector<Node>Que; // Node������ ���� Que ����

};