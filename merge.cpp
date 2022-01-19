#include<iostream>
using namespace std;

#define LENGTH 8
void insertionsort(int* A) {
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

void downinsertionsort(int* A) {
	for (int i = 1; i < LENGTH; i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] < key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}
void merge(int* A, int p, int q, int r) {

	int n1 = q - p + 1;
	int n2 = r - q;
	
	int* L = new int[n1+1];
	int* R = new int[n2+1];
	L[n1] = 100000;
	R[n2] = 100000;

	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + j+1];
	}
	
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}

	}
	delete[] L;
	delete[] R;

}
void downmerge(int* A, int p, int q, int r) {

	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	L[n1] = -1;
	R[n2] = -1;

	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + j + 1];
	}

	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] >= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}

	}
	delete[] L;
	delete[] R;

}
void MergeSort(int* A, int p, int r, int &x) 
{
	if (p < r)
	{
		int q  = (p + r) / 2;      
		MergeSort(A, p, q,x);     
		MergeSort(A, q + 1, r,x);

		if (x == 1)
			merge(A, p, q, r);
		else if (x == 2)
			downmerge(A, p, q, r);
	}
	
}

void input(int* A) {
	cout << "input " << LENGTH << " numbers : ";
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

void chooseupdown(int& x) {
	do {
		cout << endl << "1. 오름차순  2. 내림차순  3. 종료" << endl;
		cin >> x;
		if (x > 3 || x < 1)
		{
			cout << "Wrong number( 1 or 2 or 3)" << endl;
		}
		
	} while (x < 1 || x > 3);
}
void choosesort(int& y) {
	do {
		cout << endl << "1. 삽입 정렬  2. 합병 정렬  3. 종료" << endl;
		cin >> y;
		if (y > 3 || y < 1)
		{
			cout << "Wrong number( 1 or 2 or 3)" << endl;
		}

	} while (y < 1 || y > 3);
}
int main() {
	while (1) {
		int x; //choice up/down
		int y; //choice sort
		
		int A[LENGTH] = { 0 };

		chooseupdown(x);
		if (x == 3) {
			cout << "종료 합니다" << endl;
			return 0;
		}
		input(A);

		if (x == 1)
		{
			cout << "오름차순 정렬을 시작 합니다" << endl;
			choosesort(y);
			if (y == 3) {
				cout << "종료 합니다" << endl;
				return 0;
			}

			if (y == 1) {
				cout << "삽입 정렬을 시작 합니다" << endl;
				insertionsort(A);
				
			}
			else if (y == 2) {
				cout << "합병 정렬을 시작 합니다" << endl;
				MergeSort(A, 0, LENGTH-1,x);
				
			}
			
		}
		else if (x == 2) {
			cout << "내림차순 정렬을 시작 합니다" << endl;
			choosesort(y);
			if (y == 3) {
				cout << "종료 합니다" << endl;
				return 0;
			}

			if (y == 1) {
				cout << "삽입 정렬을 시작 합니다" << endl;
				downinsertionsort(A);
			}
			else if (y == 2) {
				cout << "합병 정렬을 시작 합니다" << endl;
				MergeSort(A, 0, LENGTH-1,x);
			
			}
			
		}
		output(A);
	}
	

	return 0;

}