#include"Priority_Queue.h"
#include"Adjacency_List.h"

int input(vector<int>& v) {
	ifstream fin;
	fin.open("graph5.txt");
	if (!fin) {
		cout << "������ �������� �ʽ��ϴ�";
		return 0;
	}
	int number, distance; // ������ �ִ� path�� ���� , distance
	fin >> number; // ������ ���ڸ� �ľ�
	while (1) { // ������ ���� ���������� ���� v�� ������
		fin >> distance;
		v.push_back(distance);
		if (fin.eof())
			break;
	}
	fin.close();
	return number; // vector v�� ������ ���� ����Ǿ���, number���� ��ȯ
}
int main() {
	Adjacency_List List; 
	vector<int>v; // ���� ������ �� �� ���⿡ ���� ���
	int size = input(v); //���Ϳ� �� �Է� , �� �������� ����
	if (size == 0) // input �Լ��� int�̱⿡ ������ ��� 0�� ��ȯ�Ǹ鼭 ����, size�� 0�̸� ������ ���ų� or ���Ͼȿ� path�� 0�ΰ��
		return 0;

	List.Make_List(v, size); // ���Ͽ��� �о�� ���� �Ѱ���
	List.DIJKSTRA(v, size);

	return 0;

}