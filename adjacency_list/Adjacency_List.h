#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
struct Node {
	int start;
	int vertex;
	int edge;
	struct Node* link;
};
struct List {
	Node* head; //����Ʈ�� �Ӹ�
	Node* last; //����Ʈ�� ������
};
class Adjacency_List {

private:
	vector<int> d, pi, w; // ���������� ���� distance �� pi�� ���ͷ� ����
public:
	Node* r = NULL;
	List* G; // ���ͷ� �޾ƿ� �����͸� ���Ḯ��Ʈ�� ����
	void DIJKSTRA(vector<int>& v, int size); 
	void ApendTerm(List* input, int vertex, int edge, int start, Node* last); // project 2�� LinkedList�� �Լ� ���
	void INITIALIZE_SINGLE_SOURCE(int size); // d,pi,w�� �ʱ�ȭ ���ִ� ����
	void Make_List(vector<int>& v, int size); // ������ ���͸� ����Ʈ�� ����� ����
	void Output(); // ����Լ�
};

