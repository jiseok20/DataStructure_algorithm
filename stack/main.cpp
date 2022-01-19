#include"stack.h"
#include"stack.cpp"
void input(string& x) {
	cout << "������ �Է��ϼ��� : ";
	cin >> x;
}
void output_math(string& x) { //���� ǥ�� ���� ��� , ���� ��� ���� double�̰� ����ǥ����� string�̾ ����Լ��� 2��
	cout <<"���� ǥ�� �� : "<<  x;
}
void output_solution(double& x) { // ���� �� ��� �� ��� �Լ�
	cout << endl << "��� ��: " << x << endl;
}
void check_ERROR(int x) { //���� ��� �Լ� // ���������� ȣ���ؼ� default�� �ʿ����
	switch (x)
	{
	case 1:
		cout <<endl <<"ERROR 1 : 0���� ���� �� �����ϴ�" << endl;
		break;
	case 2:
		cout << endl << "ERROR 2: ��ȣ�� ������ ���� �ʽ��ϴ�" << endl;
		break;
	case 3:
		cout << endl << "ERROR 3: �߸��� ������ �Դϴ�" << endl;
		break;
	case 4:
		cout << endl << "ERROR 4: �Ŀ� ��ȣ�� �־��ּ���" << endl;
		break;
	case 5:
		cout << endl << "ERROR 5: �Ŀ��� ��ȣ�� �������� ������ ��ġ�ؾ� �մϴ�." << endl;
		break;
	}
}
double calculation(string& y,int& ending) { // ���� ǥ�� ������ ���� �Լ� ,���ĵ� �İ� ���������� ������// ��� ���� �Ҽ������� �Ǵ� ��쵵 �־ double ���
	Stack <double> stack(y.size());
	double num; //stack�� �ִ� �ǿ����ڸ� ���ڷ� �ٲٱ� ���� ����
	double sum = 0; // ���� ����� ������ double ����
	double a, b; // stack�� �ִ� ������ pop�Ҷ� ����ϴ� ����
	char str[1000];
	char* context = NULL;
	strcpy_s(str, y.c_str()); 
	char* z = strtok_s(str, " ", &context); //string�� " "�� �������� ���� �ϱ� ����
	num = stod(z); // " " �� �������� �߸� z�� double num���� ��ȯ , ������ ���̶�� ���ڰ� ���� ���� �տ� �ֱ⿡ ���
	stack.Push(num); // num ���� stack�� ����
	while (1) {
		z = strtok_s(NULL, " ", &context); // ������ �ѹ� �߶� �� ���� ������� �ڸ���
		if (z == NULL) // ���̻� �ڸ� ���� ���ٸ� �ݺ��� break
			break;
		if ((string)z == "+") { //�߶� z�� + ��� stack�� ����� ���� 2�� pop �� �� ����, �׸��� �ٽ� ���ÿ� ���� , ������ �߶󳻴� �������� char�� ���߱�  ������ (string)���� ��������ȯ
			stack.Pop(a);
			stack.Pop(b);
			sum = a + b; //������ �ϱ� ���� a,b,sum���� ������
			stack.Push(sum);
		}
		else if ((string)z == "-") { // + ���� ����, �׷��� LIFO�� Stack�� ���� ����, a-b�� �ϸ� ������� �ٸ�
			stack.Pop(a);
			stack.Pop(b);
			sum = b - a;
			stack.Push(sum);
		}
		else if ((string)z == "*") { // * ����
			stack.Pop(a);
			stack.Pop(b);
			sum = a * b;
			stack.Push(sum);
		}
		else if ((string)z == "/") { // ������ ����, -�� ���ó�� a/b�� �ϸ� ������� �ٸ�
			stack.Pop(a);
			stack.Pop(b);
			if (a == 0) { //������ ���� 0�̸� error ���, �����ڵ� 1 ��� �� ending�� -1�� �ٲ㼭 main���� �ݺ��� Ż��
				check_ERROR(1);
				ending = -1;
				return 0;
			}
			else {
				sum = b / a;
				stack.Push(sum);
			}
		}
		else { //���� �����ڰ� �ƴ϶�� ���ڶ�� �ǹ� �̹Ƿ� double ������ �ٲ��� ���ÿ� ����, 
			   //������ or ���ڰ� �ƴ� ���� ����. ���ĺ��̳� ������ �����ڰ� �ƴѰ�� postfix���� �ɷ����� ����
			num = stod(z);
			stack.Push(num);
		}
	}
	stack.Pop(sum); // ������ �� �� �� �ݺ��� Ż���ϸ� ���� ��� �� pop
	output_solution(sum); // pop ���� ����Լ��� ����
}
int postfix(string& x,int& ending) { //�Է°��� ���� ������ ������ ����ǥ�� ��ȯ �Լ�, ���� �� Ż���� ���� int��
	Stack <string> stack(x.size());
	int length = x.size(); //x.size()�� ���� �����Ͽ� length�� ������
	int check_number; // string�� �ִ� ���� �������� �ƴ��� �Ǻ��ϱ� ���� ����
	string y; // string�� �ϳ��� �߶� üũ�ϱ� ���� ����
	string z; // y�� ���� �ڸ� ���ڸ� string z�� �ٽ� ���ϴ� ����
	int count = 0; // ��ȣ ���� üũ�� ���� ���� , "("�� üũ
	int count2 = 0; // ���� ��������, ")"�� üũ
	int count3 = 0; //�������� ���� üũ

	for (int i = 0; i < length; i++) {
		y = x[i];
		if (y == "(") {
			count++;
		}
		else if (y == ")") {
			count2++;
			stack.Pop(y);
			z = z + " " + y; // ��� �� ������ �������� �ϱ� ������ " " �߰�
		}
		else if ((y == "*") || (y == "/") || (y == "+") || (y == "-")) {
			z = z + " "; // 10�� 1 0�� �ƴ� 10�� �Ǳ� ����
			count3++;
			stack.Push(y);
		}
		else {
			check_number = atoi(y.c_str()); // ���� ��찡 �ƴϸ� �������� �߸��� �Է����� �˾ƾ� �ϱ� ������ atoi �����Լ� ���
			if ((check_number !=0) || y.compare("0")==0) //atoi�� 0���� Ȯ���ϰ� ���ڿ��μ� 0���� Ȯ��, ���� �ϳ��� ������ ����
				z = z + y;
			else {
				check_ERROR(3); //���ڵ� �����ڵ� �ƴ϶�� �߸��� �Է��̹Ƿ� ERROR 3 ��� �� ���α׷� ����
				ending = -1;
				return 0;
			}
		}
	}
	if (count != count2) { //��ȣ�� ������ ���� �ʴ� ��� ���� ���
		check_ERROR(2);
		ending = -1;
		return 0;
	}
	if (count == 0) { // count = "(" üũ ������, �̰� �ƿ� 0�̸� ��ȣ�� �ϳ��� ���ٴ� ���̹Ƿ� ���� ������ ���� ���
		check_ERROR(4);
		ending = -1;
		return 0;
	}
	if (count != count3) { //��ȣ�� ������ ���� ����üũ �� �����ڿ� ������ �´��� Ȯ��
		check_ERROR(5);
		ending = -1;
		return 0;
	}
	output_math(z); // ����ǥ�⺯ȯ �� ���
	calculation(z,ending); // ��ȯ ���� ����ϴ� �Լ�
}
int main() {
	string x; //�Է¹��� ����
	int ending = 0; // �ݺ��� ���� ���� ���� // �� error ���� ending = -1
	while (ending == 0) { //ERROR ��� �� ���α׷� ����
		input(x); // string �Է°� �ޱ�
		postfix(x, ending); // ����ǥ��� ��ȯ �Լ�, �� �ȿ� ����Լ��� ����Լ��� ���� ����
	}
}