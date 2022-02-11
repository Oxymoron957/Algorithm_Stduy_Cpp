/*
연산자 끼워넣기
https://www.acmicpc.net/problem/14888

N개의 수
N-1개의 연산자
--> 수 사이사이에 연산자를 넣어서 수식 만들수 있다.
--> 만들 수 있는 수식의 최댓값을 계산하라

--> 어떻게 수열과 연산자의 모든 경우의 수를 찾아낼 수 있을까
*/

#include <iostream>
using namespace std;

int n;
int num_arr[11];
int ops_arr[4]; // + - * /
int minout = 1000000001;
int maxout = -1000000001;

void get_answer(int result, int idx) { // 지금까지의 연산값 : result, 지금까지 연산한 순서 : idx
	if (idx == n) {
		if (result > maxout)
			maxout = result;
		if (result < minout)
			minout = result;
		return ;
	}

	for (int i=0; i<4; i++) {
		if (ops_arr[i] > 0) {// 아직 해당 연산자가 남아있다면
			ops_arr[i]--; // 해당 연산자를 사용한다.

			if (i == 0) // + 연산을 사용한다.
				get_answer(result+num_arr[idx], idx+1);
			else if (i == 1) // - 연산을 사용한다.
				get_answer(result-num_arr[idx], idx+1);
			else if (i == 2) // * 연산을 사용한다.
				get_answer(result*num_arr[idx], idx+1);
			else if (i == 3) // / 연산을 사용한다.
				get_answer(result/num_arr[idx], idx+1);
			
			ops_arr[i]++; // 다음 시나리오로 가기 위해 원상복구 
		}
	}
	return ;
}

int main(void) {
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> num_arr[i];
	for (int i=0; i<4; i++)
		cin >> ops_arr[i];

	get_answer(num_arr[0], 1);

	cout << maxout;
	cout << "\n";
	cout << minout;

	return 0;
}