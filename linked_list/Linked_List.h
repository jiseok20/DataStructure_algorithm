#pragma once
#include<iostream>
#include<string>
using namespace std;
class LinkedList {
private:
	int cnt = 0; //output�Լ����� ������ / ������ ǥ���� ���� ����
public:

	struct Node { //��� ����ü
		float coef; //���
		int expo; //����
		struct Node* link; //������ �ּ�
	};
	struct List {
		Node* head; //����Ʈ�� �Ӹ�
		Node* last; //����Ʈ�� ������
	};
	Node* r = NULL; //last ȣ��� ����
	void GetNumber(string& x, string &y); // ������ �Է¹޴� �Լ� , string���� ���׽� 1,2�� �Է� ����
	void StringToNum(string& j, string& l, List* A, List* B); // GetNumber���� ���� ���ڿ��� ���ڷ� �ٲٴ� �Լ�
	void ApendTerm(List* input,float coef,int expo,Node* last); // ����� ������ ��忡 �����ϴ� �Լ�
	List* AddPoly(List* A, List* B); // �� ���׽��� ���ϴ� �Լ�
	List* MultiPoly(List* A, List* B); //�� ���׽��� ���ϴ� �Լ�
	string Decollate(string &x); // GetNumber �Լ����� string���� ����� ������ �̾Ƴ��� �Լ�
	void Output(List* L); //��� �Լ�
	void CheckError(int x); //�������� ����
	bool CheckDescending(string& x); // �������� �˻� �Լ�
	
};