#include"Linked_List.h"

LinkedList::List* LinkedList::AddPoly(List* A,List* B) //다항식 A,B
{
	struct Node* p = A->head;
	struct Node* q = B->head;
	List* C = new List; //결과값 저장
	C->head = NULL;
	float sum;

	while (p != NULL && q != NULL) {
		if (p->expo == q->expo) { // 지수가 같으면 각 식의 계수를 더함
			sum = p->coef + q->coef;
			
				ApendTerm(C, sum, p->expo, r); //더한 값을 다시 식 C의 노드에 저장
				p = p->link; //다음 주소로 이동
				q = q->link; //다음 주소로 이동
			
		}
		else if (p->expo < q->expo) { //q의 계수가 더 큰 경우 더하기 X, 노드에 q의 값을 저장
			ApendTerm(C, q->coef, q->expo, r);
			q = q->link;
		}
		else { //p의 계수에 대해서도 위와 같음
			ApendTerm(C, p->coef, p->expo, r);
			p = p->link;
		}
	}

	while (p != NULL) { //p의 나머지 항들을 복사
		ApendTerm(C, p->coef, p->expo, r);
		p = p->link;

	}
	while (q != NULL) { //q의 나머지 항들을 복사
		ApendTerm(C, q->coef, q->expo, r);
		q = q->link;
	}
	return C; //더한 결과를 리턴
}
LinkedList::List* LinkedList::MultiPoly(List* A, List* B)
{
	struct Node* p = A->head;
	struct Node* q = B->head;
	List* D = new List; //곱셈 결과를 저장할 리스트 , 2개인 이유는 하나씩 해서 지수가 같은 값을 더하기 위함
	List* E = new List;
	E->head = NULL;
	D->head = NULL;
	float sum;
	int exsum; //expo의 더한값을 저장하기 위함.
	int count = 0; //count로 번갈아가면서 D,E에 식을 저장하고, 그 식을 더해서 지수를 정리함.

	while (p != NULL) { //p가 마지막까지 가면 모든 곱셈을 다한 것. 반복문 탈출
		q = B->head; //q가 마지막까지 가면 p의 두번째 항부터 다시 곱해야 하기때문에 처음으로 이동
		while (q != NULL) //q가 마지막까지 가면 반복문 탈출 , 다음항에 대한 계산시작
		{
			if (count == 0) //처음 값은 D리스트에 저장 
			{
				sum = p->coef * q->coef; //계수는 곱하기
				exsum = p->expo + q->expo; //지수는 더하기
				
					ApendTerm(D, sum, exsum, r); //D에 값 저장
					q = q->link; //q만 한칸 옆으로 이동, 곱셈 함수기 때문에
				
			}
			else
			{
				sum = p->coef * q->coef;
				exsum = p->expo + q->expo;
				
					ApendTerm(E, sum, exsum, r); // 위와 똑같고, 이번엔 E에 저장. 이후에 계속 E에 저장함
					q = q->link;
				
			}
		}
		p = p->link; //q가 마지막까지 갔다 온 후에 p를 한칸 이동
		if(count!=0) //처음엔 E에 식이 없기 때문에 count로 조절을 함. 
			D = AddPoly(D, E); //D,E 식을 더해서 D에 다시 저장하고, 지수를 정리함
		count = 1; // 이 이후에 계산식은 E에 저장되고, 더한 D랑 합침
		E->head = NULL; // 계속 값을 추가해줘야 하기 때문에 그 전까지의 내용 삭제. 이미 D에서 합쳐져 있기때문에 상관이 없음
	}

	return D; // 모든 계산이 끝난 값을 리턴
	
}
string LinkedList::Decollate(string& x) // string을 하나하나 분할하는 함수
{
	int check_number; // string이 숫자인지 판별하는 변수
	int count = 0;// x인경우, 숫자만 있는 경우에 따라 값을 넣어주기 위한 변수
	string k; // 분할용 문자열
	string j; // 저장용 문자열
	for (int i = 0; i < x.size(); i++) {
		k = x[i];
		if (k == "+") { //+인 경우 공백
			j = j + " "; // 숫자로 바꿀 때 사용하기 위해 공백 추가
			count = 0;
			if (i == 0 || (x[i + 1] == '+') || (x[i + 1] == '-')) ///연산자의 위치가 잘못된 경우 체크
			{
				CheckError(4);
				exit(0);
			}
			
		}
		else if (k == "-") { //-인 경우 , +와 원리는 같음
			j = j + " -";
			count = 0;
			
			if ((i == 0 && (x[i + 1] == '+')) || (i == 0 && (x[i + 1] == '-'))) ///연산자의 위치가 잘못된 경우 체크
			{
				CheckError(4);
				exit(0);
			}
			if (i != 0 && x[i - 1] == '^')
				count = 1;

			
		}
		else if (k == "x") { //x인 경우
			count = 0;

			if (x[i + 1] == 'x') { //x의 경우 입력받는 값이기에 xx가 잘못된것임을 인지 못하기 때문에 에러처리
				CheckError(5);
				exit(0);
			}
			if (i == 0) //첫번째 루픈데 x면 앞에 1추가
			{
				if (x[i + 1] == '+' || x[i + 1] == '-') { //지수가 1인 경우
					j = j + "1";
				}
				else {
					j = j + "1"; //계수가 1인 경우
				}
			}

			else if (x[i - 1] == '+' || x[i - 1] == '-') { //지수가 1인 경우
				j = j + "1";
			}
			if (x[i + 1] == NULL || x[i + 1] != '^') //계수가 1인 경우
			{
				j = j + " 1";
			}
		}
		else if (k == "^") { //^인 경우이며 지수가 입력될때마다 count를 추가해서 상수항을 판별
			j = j + " ";
			if (x[i + 1] == '^') { //^의 경우 입력받는 값이기에 ^^가 잘못된것임을 인지 못하기 때문에 에러처리
				CheckError(5);
				exit(0);
			}
			if (x[i - 1] != 'x') {
				CheckError(2); //x없이 ^사용한 경우 에러처리
				exit(0); //프로그램 종료
			}
			count = 1;

		}
		else {
			check_number = atoi(k.c_str()); // 위의 경우가 아니면 숫자인지 잘못된 입력인지 알아야 하기 때문에 atoi 내장함수 사용
			if ((check_number != 0) || k.compare("0") == 0)
			{//atoi가 0인지 확인하고 문자열로서 0인지 확인, 둘중 하나라도 맞으면 숫자
				j = j + k;
				if (x[i + 1] == NULL && count==0) //맨 끝에 상수항인 경우
					j = j + " 0";

				if(count==0 && ((x[i+1]=='+' || x[i+1] =='-') && (x[i - 1] == '+' || x[i - 1] == '-')))
					j = j + " 0";
			}
			else {
				CheckError(1);
				exit(0);
			}

		}
	}
	
	if (!CheckDescending(j)) //내림차순이 맞는지 체크, 아니라면 프로그램 종료
	{
		CheckError(3);
		exit(0);
	}
	
	return j; //j를 다시 GetNumber 함수로 보냄
}
void LinkedList::ApendTerm(List* input, float coef, int expo, Node* last){ //노드에 저장하는 함수
	Node* node = new Node; //새로운 노드 선언
	node->expo = expo;
	node->coef = coef;
	node->link = NULL;

	if (input->head == NULL) { //헤드가 비어있으면 새로운 노드 추가
		input->head = node;
		last = node;
	}
	else { //이미 전에 값을 저장했다면 이어서 값을 추가
		last= input->head;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = node;
	}
	

}
void LinkedList::GetNumber(string& x, string& y) { //숫자 입력 및 변수 분할
	cout << "----다항식의 덧셈 & 곱셈 프로그램입니다----" << endl;
	cout << "첫 번째 다항식을 입력해 주세요: ";
	cin >> x;
	x = Decollate(x); //string을 잘라서 숫자만 남겨서 가져옴. 아직 string
	cout << endl << "두 번째 다항식을 입력해 주세요: ";
	cin >> y;
	y = Decollate(y);	
	
}
void LinkedList::StringToNum(string& j,string& l, List* A, List* B)
{
	float coef;
	int expo;
	int count = 1; //expo와 coef에 번갈아서 저장하기 위해서 사용
	char str[1000];
	
	Node* p = A->head; 
	Node* q = B->head;
	char* context = NULL;
	strcpy_s(str, j.c_str());
	char* z = strtok_s(str, " ", &context); //string을 " "을 기준으로 분할 하기 위함
	coef = stof(z); //첫번째는 무조건 숫자가 나오기 때문에 coef에 저장
	
	while (1) {
		z = strtok_s(NULL, " ", &context);
		if (z == NULL)
			break;
		if (count == 0) { // 0인경우 expo는 값이 아직 없기때문에 숫자로만 변환
			coef = stof(z);
			count = 1;
		}
		else if (count == 1) { //1인경우엔 coef에 값이 저장되어 있기 때문에 노드에 값을 저장
			expo = stoi(z);
			ApendTerm(A, coef, expo, r);
			count = 0;
		}
	}//A 다항식을 저장하는 부분 , 밑에는 위와 같은 원리지만 B 다항식을 저장함
	strcpy_s(str, l.c_str());
	char* z1 = strtok_s(str, " ", &context); //string을 " "을 기준으로 분할 하기 위함
	coef = stof(z1);
	count = 1;
	while (1) {
		z1 = strtok_s(NULL, " ", &context);
		if (z1 == NULL)
			break;
		if (count == 0) {
			coef = stof(z1);
			count = 1;
		}
		else if (count == 1) {
			expo = stoi(z1);
			ApendTerm(B, coef, expo, r);
			count = 0;
		}
	}
}
void LinkedList::Output(List* L) //계산값의 가독성을 높이고자 괄호 사용
{
	Node* p = L->head;
	int i = 0;
	int check_zero = 0;
	if (cnt == 0) { //cnt는 private에 선언되어있음 , 0으로 초기화되어 있음
		cout << "두 다항식의 덧셈 : ";
		cnt = 1;
	}
	else if (cnt == 1) {
		cout << "두 다항식의 곱셈 : ";
		cnt = 0;
	}
	for (; p; p = p->link) { // 연산된 값을 각 상황에 맞게 저장
		if (p->coef != 0) {
			if (p!= NULL && i!=0)
				cout << "+";
			if (p->expo == 0) //지수가 0인 경우 상수항이기 때문에 따로 출력
				cout << "(" << p->coef << ")";
			else
				cout << "(" << p->coef << "x^" << p->expo << ")";
			i = 1;
			check_zero++;
		}
	}
	if (check_zero == 0)
		cout << 0;
	cout << endl;
	
}
void LinkedList::CheckError(int x) //각 에러의 위치마다 에러번호로 받음
{
	switch (x)
	{
	case 1:
		cout << "-------지정되지 않은 입력 입니다. 프로그램을 종료합니다.-------" << endl;
		break;
	case 2:
		cout << "-------x없이 제곱 연산은 사용할 수 없습니다. 프로그램을 종료합니다.-------" << endl;
		break;
	case 3:
		cout << "-------차수를 내림차순으로 입력해주세요. 프로그램을 종료합니다-------" << endl;
		break;
	case 4:
		cout << "-------연산자의 위치가 잘못되었습니다. 프로그램을 종료합니다-------" << endl;
		break;
	case 5:
		cout << "-------잘못된 입력입니다. 프로그램을 종료합니다-------" << endl;
		break;

	default:
		break;
	}
}
bool LinkedList::CheckDescending(string& x)
{
	char* context = NULL;
	int i = 0;
	char str[1000];
	int check_number; // 지수 비교용 체크 변수
	int save_number; //지수 비교용 세이브 변수
	strcpy_s(str, x.c_str());
	char* z = strtok_s(str, " ", &context); //string을 " "을 기준으로 분할 하기 위함
	z = strtok_s(NULL, " ", &context);
	save_number = stoi(z); //맨 처음 값을 세이브
	while (1) {
		z = strtok_s(NULL, " ", &context);
		if (z == NULL)
			break;
		if (i % 2 == 1) { // 하나 건너뛰어서 값을 저장, 지수 뒤엔 계수가 있기 때문에
			check_number = stoi(z); //체크 넘버에 저장
		}
		if ((i% 2==1)&&(save_number <= check_number)) { //뒤의 지수가 앞보다 크면 내림차순 X, 종료
			return false;
		}
		if (i % 2 == 1) //마찬가지로 체크 넘버에 값이 들어있을때 save에 숫자를 다시 조정하면서 다음 지수와 비교
			save_number = check_number;
		i++;
	}
	return true;
}
		
	


