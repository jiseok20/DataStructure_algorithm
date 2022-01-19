#include"stack.h"
#include"stack.cpp"
void input(string& x) {
	cout << "수식을 입력하세요 : ";
	cin >> x;
}
void output_math(string& x) { //후위 표기 수식 출력 , 연산 결과 값은 double이고 후위표기식은 string이어서 출력함수가 2개
	cout <<"후위 표기 식 : "<<  x;
}
void output_solution(double& x) { // 연산 후 결과 값 출력 함수
	cout << endl << "결과 값: " << x << endl;
}
void check_ERROR(int x) { //에러 출력 함수 // 정수값으로 호출해서 default는 필요없음
	switch (x)
	{
	case 1:
		cout <<endl <<"ERROR 1 : 0으로 나눌 수 없습니다" << endl;
		break;
	case 2:
		cout << endl << "ERROR 2: 괄호의 갯수가 맞지 않습니다" << endl;
		break;
	case 3:
		cout << endl << "ERROR 3: 잘못된 연산자 입니다" << endl;
		break;
	case 4:
		cout << endl << "ERROR 4: 식에 괄호를 넣어주세요" << endl;
		break;
	case 5:
		cout << endl << "ERROR 5: 식에서 괄호와 연산자의 갯수는 일치해야 합니다." << endl;
		break;
	}
}
double calculation(string& y,int& ending) { // 후위 표기 수식의 연산 함수 ,정렬된 식과 엔딩조건을 참조함// 결과 값이 소수점으로 되는 경우도 있어서 double 사용
	Stack <double> stack(y.size());
	double num; //stack에 있는 피연산자를 숫자로 바꾸기 위한 변수
	double sum = 0; // 연산 결과를 저장할 double 변수
	double a, b; // stack에 있는 변수를 pop할때 사용하는 변수
	char str[1000];
	char* context = NULL;
	strcpy_s(str, y.c_str()); 
	char* z = strtok_s(str, " ", &context); //string을 " "을 기준으로 분할 하기 위함
	num = stod(z); // " " 을 기준으로 잘린 z를 double num으로 변환 , 멀쩡한 식이라면 숫자가 가장 먼저 앞에 있기에 사용
	stack.Push(num); // num 값을 stack에 저장
	while (1) {
		z = strtok_s(NULL, " ", &context); // 위에서 한번 잘라낸 후 다음 공백까지 자르기
		if (z == NULL) // 더이상 자를 것이 없다면 반복문 break
			break;
		if ((string)z == "+") { //잘라낸 z가 + 경우 stack에 저장된 변수 2번 pop 한 후 연산, 그리고 다시 스택에 저장 , 위에서 잘라내는 과정에서 char로 변했기  때문에 (string)으로 강제형변환
			stack.Pop(a);
			stack.Pop(b);
			sum = a + b; //연산을 하기 위해 a,b,sum으로 구분함
			stack.Push(sum);
		}
		else if ((string)z == "-") { // + 경우와 같음, 그러나 LIFO인 Stack의 성질 주의, a-b로 하면 결과값이 다름
			stack.Pop(a);
			stack.Pop(b);
			sum = b - a;
			stack.Push(sum);
		}
		else if ((string)z == "*") { // * 연산
			stack.Pop(a);
			stack.Pop(b);
			sum = a * b;
			stack.Push(sum);
		}
		else if ((string)z == "/") { // 나누기 연산, -의 경우처럼 a/b로 하면 결과값이 다름
			stack.Pop(a);
			stack.Pop(b);
			if (a == 0) { //나누는 값이 0이면 error 출력, 에러코드 1 출력 후 ending을 -1로 바꿔서 main문의 반복문 탈출
				check_ERROR(1);
				ending = -1;
				return 0;
			}
			else {
				sum = b / a;
				stack.Push(sum);
			}
		}
		else { //위의 연산자가 아니라면 숫자라는 의미 이므로 double 값으로 바꾼후 스택에 저장, 
			   //연산자 or 숫자가 아닌 경우는 없음. 알파벳이나 지정된 연산자가 아닌경우 postfix에서 걸러지기 때문
			num = stod(z);
			stack.Push(num);
		}
	}
	stack.Pop(sum); // 연산을 다 한 후 반복문 탈출하면 최종 결과 값 pop
	output_solution(sum); // pop 값을 출력함수로 보냄
}
int postfix(string& x,int& ending) { //입력값과 엔딩 조건을 참조한 후위표기 변환 함수, 에러 시 탈출을 위해 int형
	Stack <string> stack(x.size());
	int length = x.size(); //x.size()가 보기 불편하여 length로 재정의
	int check_number; // string에 있는 값이 숫자인지 아닌지 판별하기 위한 변수
	string y; // string을 하나씩 잘라서 체크하기 위한 변수
	string z; // y로 각각 자른 숫자를 string z로 다시 합하는 변수
	int count = 0; // 괄호 갯수 체크를 위한 변수 , "("를 체크
	int count2 = 0; // 위와 마찬가지, ")"를 체크
	int count3 = 0; //연산자의 갯수 체크

	for (int i = 0; i < length; i++) {
		y = x[i];
		if (y == "(") {
			count++;
		}
		else if (y == ")") {
			count2++;
			stack.Pop(y);
			z = z + " " + y; // 계산 시 공백을 기준으로 하기 때문에 " " 추가
		}
		else if ((y == "*") || (y == "/") || (y == "+") || (y == "-")) {
			z = z + " "; // 10이 1 0이 아닌 10이 되기 위함
			count3++;
			stack.Push(y);
		}
		else {
			check_number = atoi(y.c_str()); // 위의 경우가 아니면 숫자인지 잘못된 입력인지 알아야 하기 때문에 atoi 내장함수 사용
			if ((check_number !=0) || y.compare("0")==0) //atoi가 0인지 확인하고 문자열로서 0인지 확인, 둘중 하나라도 맞으면 숫자
				z = z + y;
			else {
				check_ERROR(3); //숫자도 연산자도 아니라면 잘못된 입력이므로 ERROR 3 출력 후 프로그램 종료
				ending = -1;
				return 0;
			}
		}
	}
	if (count != count2) { //괄호의 갯수가 맞지 않는 경우 에러 출력
		check_ERROR(2);
		ending = -1;
		return 0;
	}
	if (count == 0) { // count = "(" 체크 변수임, 이게 아예 0이면 괄호가 하나도 없다는 뜻이므로 따로 나눠서 오류 출력
		check_ERROR(4);
		ending = -1;
		return 0;
	}
	if (count != count3) { //괄호의 갯수에 대한 오류체크 후 연산자와 갯수가 맞는지 확인
		check_ERROR(5);
		ending = -1;
		return 0;
	}
	output_math(z); // 후위표기변환 식 출력
	calculation(z,ending); // 변환 식을 계산하는 함수
}
int main() {
	string x; //입력받을 변수
	int ending = 0; // 반복문 종료 조건 변수 // 각 error 마다 ending = -1
	while (ending == 0) { //ERROR 출력 시 프로그램 종료
		input(x); // string 입력값 받기
		postfix(x, ending); // 후위표기식 변환 함수, 이 안에 계산함수와 출력함수도 따로 있음
	}
}