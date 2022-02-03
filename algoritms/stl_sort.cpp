/*
sort() 함수 : 
1. algorithm 헤더에 포함되어 있음
2. 기본적으로 오름차순 정렬
3. 인수로 배열의 시작점 주소와 마지막 주소+1 
4. 비교 함수를 세번째 인자로 전달하면 해당 함수에 맞게 정렬한다. (return 값이 false일때 swap 발생)
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;

	Student(string name, int score){
		this->name = name;
		this->score = score;
	}

	bool operator <(const Student &student) const { // < 연산자 오버라이딩
		return this->score < student.score;
	}
};

bool compare(int a, int b);

int main(void){
	int arr[] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(arr, arr+10, compare);
	for(int i=0; i<10; i++){
		if (i != 0)
			cout << ", ";
		cout << arr[i];
	}
	cout << "\n";

	Student students[] = {
		Student("A", 90),
		Student("B", 93),
		Student("C", 97),
		Student("D", 87),
		Student("E", 92)
	};
	sort(students, students+5);
	for(int i=0; i<5; i++){
		cout << students[i].name << " ";
	}
	cout << "\n";
}

bool compare(int a, int b){
	return a > b; 
}
