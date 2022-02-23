/*
그림
https://www.acmicpc.net/problem/1926
*/

#include <iostream>
using namespace std;

int m, n;
int board[501][501];
bool visited[501][501];
int area;
int max_area;
int counting;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// void bfs(int x, int y) {
// 	// mark visited
// 	visited[x][y] = true;

// 	// find next position
// 	for (int i=0; i<4; i++) {
// 		int nx = x + dx[i];
// 		int ny = y + dy[i];

// 		// check nx ny valid
// 		if (nx<0 || ny<0 || nx>=n || ny>=m)
// 			return ;
// 		if (visited[x][y] == true || board[x][y] == 0)
// 			return ;
		
// 		// recursive call
// 		area += 1;
// 		bfs(nx, ny);
// 	}
// }

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// init n, m
	cin >> n >> m;
	// init board
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			string s;
			cin >> s;
			board[i][j] = s[0] - '0';
		}
	}

	// BFS
	for (int i=0; i<n; i++)


	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<m; j++) {
	// 		area = 0;
	// 		if (visited[i][j] == false) {
	// 			bfs(j, i);
	// 			counting += 1;
	// 		}
	// 		max_area = (area > max_area) ? area : max_area;
	// 	}
	// }	
	// cout << counting << "\n";
	// cout << max_area << "\n";
	return 0;
}