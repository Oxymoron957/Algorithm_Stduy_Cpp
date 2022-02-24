/*
테트로미노
https://www.acmicpc.net/problem/14500

tip : ㅗㅜㅏㅓ의 경우 dfs로 해결이 안되는 것을 유의!
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 501

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int max_value;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x, int level, int cost) {
	visited[y][x] = true;
	if (level == 4) {
		if (cost > max_value)
			max_value = cost;
			return ;
	}
	for (int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0<=ny && ny<N && 0<=nx && nx<M && visited[ny][nx] == false) {
			if (level != 4) {
				dfs(ny, nx, level+1, cost+board[ny][nx]);
				visited[ny][nx] = false;
			} 
		}
	}
}

void case1(int y, int x) {
	int temp = board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+1];
	if (temp > max_value)
		max_value = temp; 
}

void case2(int y, int x) {
	int temp = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+1];
	if (temp > max_value)
		max_value = temp; 
}

void case3(int y, int x) {
	int temp = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+1][x+1];
	if (temp > max_value)
		max_value = temp; 
}

void case4(int y, int x) {
	int temp = board[y][x] + board[y-1][x+1] + board[y][x+1] + board[y+1][x+1];
	if (temp > max_value)
		max_value = temp; 
}
 
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// input
	cin >> N >> M;
	for (int i=0; i<N;	i++)
		for(int j=0; j<M; j++)
			cin >> board[i][j];

	for (int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			memset(visited, false, sizeof(visited));
			dfs(i, j, 1, board[i][j]);
			if (i - 1 >= 0 && j + 2 < M) case1(i, j);
            if (j + 2 < M && i + 1 < N) case2(i, j);
            if (i + 2 < N && j + 1 < M) case3(i, j);
            if (i + 1 < N && i - 1 >= 0 && j + 1 < M) case4(i, j);
		}
	}
	cout << max_value << "\n";
}