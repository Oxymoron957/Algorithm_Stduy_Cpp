/*
연산자 끼워넣기
https://www.acmicpc.net/problem/14888

N개의 수
N-1개의 연산자
--> 수 사이사이에 연산자를 넣어서 수식 만들수 있다.
--> 만들 수 있는 수식의 최댓값을 계산하라
*/

#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[11] = {0};
	int op[4] = {0};
	int t = 0;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n[i];
	}
	for(int i=0; i<4; i++) {
		cin >> op[i];
	}	
	return 0;
}