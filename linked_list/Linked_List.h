#pragma once
#include<iostream>
#include<string>
using namespace std;
class LinkedList {
private:
	int cnt = 0; //output함수에서 덧셈식 / 곱셈식 표현을 위한 변수
public:

	struct Node { //노드 구조체
		float coef; //계수
		int expo; //지수
		struct Node* link; //마지막 주소
	};
	struct List {
		Node* head; //리스트의 머리
		Node* last; //리스트의 마지막
	};
	Node* r = NULL; //last 호출용 변수
	void GetNumber(string& x, string &y); // 수식을 입력받는 함수 , string으로 다항식 1,2를 입력 받음
	void StringToNum(string& j, string& l, List* A, List* B); // GetNumber에서 얻은 문자열을 숫자로 바꾸는 함수
	void ApendTerm(List* input,float coef,int expo,Node* last); // 계수와 지수를 노드에 저장하는 함수
	List* AddPoly(List* A, List* B); // 두 다항식을 더하는 함수
	List* MultiPoly(List* A, List* B); //두 다항식을 곱하는 함수
	string Decollate(string &x); // GetNumber 함수에서 string에서 계수와 지수만 뽑아내는 함수
	void Output(List* L); //출력 함수
	void CheckError(int x); //에러내용 모음
	bool CheckDescending(string& x); // 내림차순 검사 함수
	
};