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
	Node* head; //리스트의 머리
	Node* last; //리스트의 마지막
};
class Adjacency_List {

private:
	vector<int> d, pi, w; // 최종적으로 받을 distance 와 pi를 벡터로 선언
public:
	Node* r = NULL;
	List* G; // 벡터로 받아온 데이터를 연결리스트로 묶음
	void DIJKSTRA(vector<int>& v, int size); 
	void ApendTerm(List* input, int vertex, int edge, int start, Node* last); // project 2의 LinkedList의 함수 사용
	void INITIALIZE_SINGLE_SOURCE(int size); // d,pi,w를 초기화 해주는 역할
	void Make_List(vector<int>& v, int size); // 가져온 벡터를 리스트로 만들기 위함
	void Output(); // 출력함수
};

