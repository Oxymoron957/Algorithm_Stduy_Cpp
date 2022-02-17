/*
연결 요소의 개수
https://www.acmicpc.net/problem/11724
*/

#include <iostream>
using namespace std;

bool map[1001][1001]; // node간의 연결 상태를 나타내는 변수
bool check[1001]; // node의 정보를 나타내는 변수
int n, m, count_;

void dfs(int num) {
	check[num] = true; // 해당 node는 방문한 것으로 처리

	for(int i=1; i<=n; i++) { // 모든 node에 대하여 
		if (map[num][i] && !check[i]) { // num node가 i번째 node와 연결되어있고 방문하지 않았다면 
			// ith node에 대하여 다시 호출한다.
			dfs(i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int start, end;
		cin >> start >> end;

		// node간의 연결정보 초기화
		map[start][end] = true;
		map[end][start] = true;
	}
	
	for(int i=1; i<=n; i++) { // 두번째 node부터 시작한다. 
		if (!check[i]) { // node마다 방문되어있지 않다면 dfs 함수 호출 및 count 증가
			count_++;
			dfs(i);
		}
	}
	cout << count_ << "\n";
	return 0;
}