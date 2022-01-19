#include"Linked_List.h"

LinkedList::List* LinkedList::AddPoly(List* A,List* B) //���׽� A,B
{
	struct Node* p = A->head;
	struct Node* q = B->head;
	List* C = new List; //����� ����
	C->head = NULL;
	float sum;

	while (p != NULL && q != NULL) {
		if (p->expo == q->expo) { // ������ ������ �� ���� ����� ����
			sum = p->coef + q->coef;
			
				ApendTerm(C, sum, p->expo, r); //���� ���� �ٽ� �� C�� ��忡 ����
				p = p->link; //���� �ּҷ� �̵�
				q = q->link; //���� �ּҷ� �̵�
			
		}
		else if (p->expo < q->expo) { //q�� ����� �� ū ��� ���ϱ� X, ��忡 q�� ���� ����
			ApendTerm(C, q->coef, q->expo, r);
			q = q->link;
		}
		else { //p�� ����� ���ؼ��� ���� ����
			ApendTerm(C, p->coef, p->expo, r);
			p = p->link;
		}
	}

	while (p != NULL) { //p�� ������ �׵��� ����
		ApendTerm(C, p->coef, p->expo, r);
		p = p->link;

	}
	while (q != NULL) { //q�� ������ �׵��� ����
		ApendTerm(C, q->coef, q->expo, r);
		q = q->link;
	}
	return C; //���� ����� ����
}
LinkedList::List* LinkedList::MultiPoly(List* A, List* B)
{
	struct Node* p = A->head;
	struct Node* q = B->head;
	List* D = new List; //���� ����� ������ ����Ʈ , 2���� ������ �ϳ��� �ؼ� ������ ���� ���� ���ϱ� ����
	List* E = new List;
	E->head = NULL;
	D->head = NULL;
	float sum;
	int exsum; //expo�� ���Ѱ��� �����ϱ� ����.
	int count = 0; //count�� �����ư��鼭 D,E�� ���� �����ϰ�, �� ���� ���ؼ� ������ ������.

	while (p != NULL) { //p�� ���������� ���� ��� ������ ���� ��. �ݺ��� Ż��
		q = B->head; //q�� ���������� ���� p�� �ι�° �׺��� �ٽ� ���ؾ� �ϱ⶧���� ó������ �̵�
		while (q != NULL) //q�� ���������� ���� �ݺ��� Ż�� , �����׿� ���� ������
		{
			if (count == 0) //ó�� ���� D����Ʈ�� ���� 
			{
				sum = p->coef * q->coef; //����� ���ϱ�
				exsum = p->expo + q->expo; //������ ���ϱ�
				
					ApendTerm(D, sum, exsum, r); //D�� �� ����
					q = q->link; //q�� ��ĭ ������ �̵�, ���� �Լ��� ������
				
			}
			else
			{
				sum = p->coef * q->coef;
				exsum = p->expo + q->expo;
				
					ApendTerm(E, sum, exsum, r); // ���� �Ȱ���, �̹��� E�� ����. ���Ŀ� ��� E�� ������
					q = q->link;
				
			}
		}
		p = p->link; //q�� ���������� ���� �� �Ŀ� p�� ��ĭ �̵�
		if(count!=0) //ó���� E�� ���� ���� ������ count�� ������ ��. 
			D = AddPoly(D, E); //D,E ���� ���ؼ� D�� �ٽ� �����ϰ�, ������ ������
		count = 1; // �� ���Ŀ� ������ E�� ����ǰ�, ���� D�� ��ħ
		E->head = NULL; // ��� ���� �߰������ �ϱ� ������ �� �������� ���� ����. �̹� D���� ������ �ֱ⶧���� ����� ����
	}

	return D; // ��� ����� ���� ���� ����
	
}
string LinkedList::Decollate(string& x) // string�� �ϳ��ϳ� �����ϴ� �Լ�
{
	int check_number; // string�� �������� �Ǻ��ϴ� ����
	int count = 0;// x�ΰ��, ���ڸ� �ִ� ��쿡 ���� ���� �־��ֱ� ���� ����
	string k; // ���ҿ� ���ڿ�
	string j; // ����� ���ڿ�
	for (int i = 0; i < x.size(); i++) {
		k = x[i];
		if (k == "+") { //+�� ��� ����
			j = j + " "; // ���ڷ� �ٲ� �� ����ϱ� ���� ���� �߰�
			count = 0;
			if (i == 0 || (x[i + 1] == '+') || (x[i + 1] == '-')) ///�������� ��ġ�� �߸��� ��� üũ
			{
				CheckError(4);
				exit(0);
			}
			
		}
		else if (k == "-") { //-�� ��� , +�� ������ ����
			j = j + " -";
			count = 0;
			
			if ((i == 0 && (x[i + 1] == '+')) || (i == 0 && (x[i + 1] == '-'))) ///�������� ��ġ�� �߸��� ��� üũ
			{
				CheckError(4);
				exit(0);
			}
			if (i != 0 && x[i - 1] == '^')
				count = 1;

			
		}
		else if (k == "x") { //x�� ���
			count = 0;

			if (x[i + 1] == 'x') { //x�� ��� �Է¹޴� ���̱⿡ xx�� �߸��Ȱ����� ���� ���ϱ� ������ ����ó��
				CheckError(5);
				exit(0);
			}
			if (i == 0) //ù��° ���µ� x�� �տ� 1�߰�
			{
				if (x[i + 1] == '+' || x[i + 1] == '-') { //������ 1�� ���
					j = j + "1";
				}
				else {
					j = j + "1"; //����� 1�� ���
				}
			}

			else if (x[i - 1] == '+' || x[i - 1] == '-') { //������ 1�� ���
				j = j + "1";
			}
			if (x[i + 1] == NULL || x[i + 1] != '^') //����� 1�� ���
			{
				j = j + " 1";
			}
		}
		else if (k == "^") { //^�� ����̸� ������ �Էµɶ����� count�� �߰��ؼ� ������� �Ǻ�
			j = j + " ";
			if (x[i + 1] == '^') { //^�� ��� �Է¹޴� ���̱⿡ ^^�� �߸��Ȱ����� ���� ���ϱ� ������ ����ó��
				CheckError(5);
				exit(0);
			}
			if (x[i - 1] != 'x') {
				CheckError(2); //x���� ^����� ��� ����ó��
				exit(0); //���α׷� ����
			}
			count = 1;

		}
		else {
			check_number = atoi(k.c_str()); // ���� ��찡 �ƴϸ� �������� �߸��� �Է����� �˾ƾ� �ϱ� ������ atoi �����Լ� ���
			if ((check_number != 0) || k.compare("0") == 0)
			{//atoi�� 0���� Ȯ���ϰ� ���ڿ��μ� 0���� Ȯ��, ���� �ϳ��� ������ ����
				j = j + k;
				if (x[i + 1] == NULL && count==0) //�� ���� ������� ���
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
	
	if (!CheckDescending(j)) //���������� �´��� üũ, �ƴ϶�� ���α׷� ����
	{
		CheckError(3);
		exit(0);
	}
	
	return j; //j�� �ٽ� GetNumber �Լ��� ����
}
void LinkedList::ApendTerm(List* input, float coef, int expo, Node* last){ //��忡 �����ϴ� �Լ�
	Node* node = new Node; //���ο� ��� ����
	node->expo = expo;
	node->coef = coef;
	node->link = NULL;

	if (input->head == NULL) { //��尡 ��������� ���ο� ��� �߰�
		input->head = node;
		last = node;
	}
	else { //�̹� ���� ���� �����ߴٸ� �̾ ���� �߰�
		last= input->head;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = node;
	}
	

}
void LinkedList::GetNumber(string& x, string& y) { //���� �Է� �� ���� ����
	cout << "----���׽��� ���� & ���� ���α׷��Դϴ�----" << endl;
	cout << "ù ��° ���׽��� �Է��� �ּ���: ";
	cin >> x;
	x = Decollate(x); //string�� �߶� ���ڸ� ���ܼ� ������. ���� string
	cout << endl << "�� ��° ���׽��� �Է��� �ּ���: ";
	cin >> y;
	y = Decollate(y);	
	
}
void LinkedList::StringToNum(string& j,string& l, List* A, List* B)
{
	float coef;
	int expo;
	int count = 1; //expo�� coef�� �����Ƽ� �����ϱ� ���ؼ� ���
	char str[1000];
	
	Node* p = A->head; 
	Node* q = B->head;
	char* context = NULL;
	strcpy_s(str, j.c_str());
	char* z = strtok_s(str, " ", &context); //string�� " "�� �������� ���� �ϱ� ����
	coef = stof(z); //ù��°�� ������ ���ڰ� ������ ������ coef�� ����
	
	while (1) {
		z = strtok_s(NULL, " ", &context);
		if (z == NULL)
			break;
		if (count == 0) { // 0�ΰ�� expo�� ���� ���� ���⶧���� ���ڷθ� ��ȯ
			coef = stof(z);
			count = 1;
		}
		else if (count == 1) { //1�ΰ�쿣 coef�� ���� ����Ǿ� �ֱ� ������ ��忡 ���� ����
			expo = stoi(z);
			ApendTerm(A, coef, expo, r);
			count = 0;
		}
	}//A ���׽��� �����ϴ� �κ� , �ؿ��� ���� ���� �������� B ���׽��� ������
	strcpy_s(str, l.c_str());
	char* z1 = strtok_s(str, " ", &context); //string�� " "�� �������� ���� �ϱ� ����
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
void LinkedList::Output(List* L) //��갪�� �������� ���̰��� ��ȣ ���
{
	Node* p = L->head;
	int i = 0;
	int check_zero = 0;
	if (cnt == 0) { //cnt�� private�� ����Ǿ����� , 0���� �ʱ�ȭ�Ǿ� ����
		cout << "�� ���׽��� ���� : ";
		cnt = 1;
	}
	else if (cnt == 1) {
		cout << "�� ���׽��� ���� : ";
		cnt = 0;
	}
	for (; p; p = p->link) { // ����� ���� �� ��Ȳ�� �°� ����
		if (p->coef != 0) {
			if (p!= NULL && i!=0)
				cout << "+";
			if (p->expo == 0) //������ 0�� ��� ������̱� ������ ���� ���
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
void LinkedList::CheckError(int x) //�� ������ ��ġ���� ������ȣ�� ����
{
	switch (x)
	{
	case 1:
		cout << "-------�������� ���� �Է� �Դϴ�. ���α׷��� �����մϴ�.-------" << endl;
		break;
	case 2:
		cout << "-------x���� ���� ������ ����� �� �����ϴ�. ���α׷��� �����մϴ�.-------" << endl;
		break;
	case 3:
		cout << "-------������ ������������ �Է����ּ���. ���α׷��� �����մϴ�-------" << endl;
		break;
	case 4:
		cout << "-------�������� ��ġ�� �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�-------" << endl;
		break;
	case 5:
		cout << "-------�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�-------" << endl;
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
	int check_number; // ���� �񱳿� üũ ����
	int save_number; //���� �񱳿� ���̺� ����
	strcpy_s(str, x.c_str());
	char* z = strtok_s(str, " ", &context); //string�� " "�� �������� ���� �ϱ� ����
	z = strtok_s(NULL, " ", &context);
	save_number = stoi(z); //�� ó�� ���� ���̺�
	while (1) {
		z = strtok_s(NULL, " ", &context);
		if (z == NULL)
			break;
		if (i % 2 == 1) { // �ϳ� �ǳʶپ ���� ����, ���� �ڿ� ����� �ֱ� ������
			check_number = stoi(z); //üũ �ѹ��� ����
		}
		if ((i% 2==1)&&(save_number <= check_number)) { //���� ������ �պ��� ũ�� �������� X, ����
			return false;
		}
		if (i % 2 == 1) //���������� üũ �ѹ��� ���� ��������� save�� ���ڸ� �ٽ� �����ϸ鼭 ���� ������ ��
			save_number = check_number;
		i++;
	}
	return true;
}
		
	


