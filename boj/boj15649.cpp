/*
N과 M
https://www.acmicpc.net/problem/15649
*/

#include <iostream>
using namespace std;

int arr[10];
int n, m;

int is_exist(int n, int level) {
	for (int i=0; i<level; i++) {
		if (arr[i] == n)
			return 1;
	}
	return 0;
}

void recursive_call(int level) {
	// level == m이면 출력 후 탈출
	if (level == m) {
		for (int i=0; i<m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	// 1~n까지 중복되지 않으면 놓고 recursive call
	for (int i=1; i<=n; i++) {
		if (!is_exist(i, level)) {
			arr[level] = i;
			recursive_call(level+1);
		}
	}
}

int main(void) {
	cin >> n >> m;
	recursive_call(0);
	return 0;
}