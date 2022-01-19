#include<iostream>
using namespace std;

#define LENGTH 6
void upsort(int* A) {
	for (int i = 1; i < LENGTH; i++) {
		int key = A[i];
		int j = i - 1;
		while ((i >= 0) && (A[j] > key)) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

	}
}
void downsort(int* A) {
	int tmp = 0;
	for(int i=0;i<LENGTH;i++){
		for (int j = i+1; j < LENGTH + 1; j++) {
			if (A[j] > A[i]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
	
	

}
void input(int* A) {
	cout << "input" << LENGTH << "numbers : ";
	for (int i = 0; i < LENGTH; i++) {
		cin >> A[i];
	}
}
void output(int* A) {
	cout << "Result : ";
	for (int i = 0; i < LENGTH; i++) {
		cout << A[i] << "  ";
	}
	cout << endl;

}
void choosesort(int& x) {
	do {
		cout << endl<<"1. 오름차순  2. 내림차순  3. 종료" << endl;
		cin >> x;
		if (x > 3 || x < 1)
		{
			cout << "Wrong number( 1 or 2 or 3)" << endl;
		}
	} while (x <1|| x > 3);
}
int main() {
	while (1) {
		int x; //choice number
		int A[LENGTH] = { 0 };
		choosesort(x);
		if (x == 3) {
			cout << "종료 합니다" << endl;
			return 0;
		}
		input(A);

		if (x == 1)
		{
			cout << "오름차순 정렬을 시작 합니다" << endl;
			upsort(A);
		}
		else if (x == 2) {
			cout << "내림차순 정렬을 시작 합니다" << endl;
			downsort(A);
		}
		

		output(A);
	}
	return 0;

}