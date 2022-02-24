/*
인구이동
https://www.acmicpc.net/problem/16234
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 50

int n, l, r;
int nation_peo, nation_num;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> vec;

void DFS(int y, int x) {
	for (int i=0; i<4; i++) {
		// next position 계산
		int ny = y + dy[i];
		int nx = x + dx[i];

		// cur position과의 차이 계산
		int diff = abs(board[y][x] - board[ny][nx]);
		// valid postion인지 검사
		if (0 <= ny && ny < n && 0 <= nx && nx < n) {
			if (l <= diff && diff <= r && visited[ny][nx] == false) {
				// valid하다면 visited 처리 / vector에 추가 / nation_peo, nation_num 증가
				visited[ny][nx] = true;
				vec.push_back(make_pair(ny, nx));
				nation_peo += board[ny][nx];
				nation_num += 1;

				// 재귀 처리
				DFS(ny, nx);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	// input
	cin >> n >> l >> r;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}

	int result = 0;
	while (true) {
		memset(visited, false, sizeof(visited)); // visited array initialized

		bool peo_moved = false;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				// 이미 방문한 곳이라면 continue;
				if (visited[i][j] == true)
					continue ;
				
				// 해당 board visited 처리 및 nation_peo, nation_num 초기화
				visited[i][j] = true;
				nation_peo = board[i][j];
				nation_num = 1;

				// DFS를 위한 객체 초기화
				vec.clear();
				vec.push_back(make_pair(i, j));

				// DFS 순회
				DFS(i, j);

				// 두개 이상의 국가를 순회했다면 
				if (nation_num >= 2) {
					peo_moved = true;

					for (int i=0; i<vec.size(); i++) {
						board[vec[i].first][vec[i].second] = nation_peo / nation_num;
					}
				}
			}
		}
		// 한번이라도 인구이동이 발생했다면 다음 루프로 이동
		if (peo_moved == true)
			result += 1;
		else
			break ;
	}
	cout << result << "\n";
	
	return 0;
}