#include"Linked_List.h"

int main(){
	string x, y; //입력받은 식을 저장
	LinkedList polynomial;
	
	LinkedList::List*A = new LinkedList::List;
	A->head = NULL;
	LinkedList::List* B = new LinkedList::List;
	B->head = NULL;
	LinkedList::List* C =new LinkedList::List;
	C->head = NULL;
	LinkedList::List* D= new LinkedList::List;
	D->head = NULL;

	polynomial.GetNumber(x,y); // 값을 입력 받음
	polynomial.StringToNum(x, y,A,B); //받은 스트링을 숫자로 변환
	C = polynomial.AddPoly(A, B); // 리스트에 저장된 값을 더해서 C에 저장
	polynomial.Output(C); // 계산결과 출력
	D = polynomial.MultiPoly(A, B); //리스트에 저장된 값을 곱해서 D에 저장
	polynomial.Output(D); //계산결과 출력
	
	delete A;
	delete B;
	delete C;
	delete D;
	
	return 0;
}