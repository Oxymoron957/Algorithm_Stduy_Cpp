/*
N-Queen
https://www.acmicpc.net/problem/9663
*/

#include <iostream>
using namespace std;

int board[15];
int input_size;
int answer;

int check_valid(int level) {
	for (int i=0; i<level; i++) {
		if(board[i] == board[level]) // 같은 라인에 있을 경우 x
			return 0;
		if(abs(board[level]-board[i]) == level-i) // 대각선에 있을 경우 x
			return 0; 
	}
	return 1;
}

// 재귀함수 -> 이전 Level까지 맞는다고 가정하고 Level에 맞는 퀸의 위치를 선정한다. 
void nqueen(int level) {
	if (level == input_size)
		answer += 1;
	for (int i=0; i<input_size; i++) {
		board[level] = i; // level에 queen 하나 놓기
		if(check_valid(level)) // 새로 놓은 level이 valid하다면 다음 level로 이동
			nqueen(level+1);
	}
}

int main(void) {
	cin >> input_size;
	nqueen(0);
	cout << answer;
}
