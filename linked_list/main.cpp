#include"Linked_List.h"

int main(){
	string x, y; //�Է¹��� ���� ����
	LinkedList polynomial;
	
	LinkedList::List*A = new LinkedList::List;
	A->head = NULL;
	LinkedList::List* B = new LinkedList::List;
	B->head = NULL;
	LinkedList::List* C =new LinkedList::List;
	C->head = NULL;
	LinkedList::List* D= new LinkedList::List;
	D->head = NULL;

	polynomial.GetNumber(x,y); // ���� �Է� ����
	polynomial.StringToNum(x, y,A,B); //���� ��Ʈ���� ���ڷ� ��ȯ
	C = polynomial.AddPoly(A, B); // ����Ʈ�� ����� ���� ���ؼ� C�� ����
	polynomial.Output(C); // ����� ���
	D = polynomial.MultiPoly(A, B); //����Ʈ�� ����� ���� ���ؼ� D�� ����
	polynomial.Output(D); //����� ���
	
	delete A;
	delete B;
	delete C;
	delete D;
	
	return 0;
}