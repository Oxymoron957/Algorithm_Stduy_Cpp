/*
에디터
https://www.acmicpc.net/problem/1406

영어 소문자만 기록가능
600,000 글자까지 입력가능

L : 커서를 왼쪽 한칸 옮김
D : 커서를 오른쪽으로 한칸 옮김
B : 커서 왼쪽에 있는 문자 삭제 & 오른쪽 글자는 그대로 
P $ : $라는 문자를 커서 왼쪽에 추가한다.
*/

#include <iostream>
#include <list>
using namespace std;

int main(void) {
	string initial_string;
	cin >> initial_string;
	list<char> li; // list stl 선언
	
	for(auto c:initial_string) 
		li.push_back(c); 
	auto cursor = li.end(); // .end() : 끝나는 지점의 iterator 

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		char op;
		cin >> op;

		if (op == 'L' && cursor != li.begin()) // .begin() : 시작하는 지점의 iterator
			cursor--;
		else if (op == 'D' && cursor != li.end())
			cursor++;
		else if (op == 'P') {
			char c;
			cin >> c;
			li.insert(cursor, c); // insert() : 해당 iterator에 원소 삽입
		}
		else if (op == 'B' && cursor != li.begin()) {
			cursor--;
			cursor = li.erase(cursor); // erase() : 해당 iterator의 원소 삭제 후 iterator 반환 
		}
	}
	for(auto c:li)
		cout << c;
	cout << "\n";
	return 0;
}