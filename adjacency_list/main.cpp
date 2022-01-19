#include"Priority_Queue.h"
#include"Adjacency_List.h"

int input(vector<int>& v) {
	ifstream fin;
	fin.open("graph5.txt");
	if (!fin) {
		cout << "파일이 존재하지 않습니다";
		return 0;
	}
	int number, distance; // 맨위에 있는 path의 숫자 , distance
	fin >> number; // 맨위의 숫자를 파악
	while (1) { // 루프를 돌며 끝날때까지 값을 v에 저장함
		fin >> distance;
		v.push_back(distance);
		if (fin.eof())
			break;
	}
	fin.close();
	return number; // vector v는 참조라서 값이 저장되었고, number만을 반환
}
int main() {
	Adjacency_List List; 
	vector<int>v; // 받을 갯수를 알 수 없기에 벡터 사용
	int size = input(v); //벡터에 값 입력 , 총 갯수까지 추출
	if (size == 0) // input 함수가 int이기에 파일이 없어도 0이 반환되면서 오류, size가 0이면 파일이 없거나 or 파일안에 path가 0인경우
		return 0;

	List.Make_List(v, size); // 파일에서 읽어온 값을 넘겨줌
	List.DIJKSTRA(v, size);

	return 0;

}