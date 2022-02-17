/*
미로 탐색
https://www.acmicpc.net/problem/2178
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool map[101][101];
bool visited[101][101];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> v;

void dfs(int x, int y, int cost) {
	// 만약 끝까지 도착했다면 출력한다.
	if(x==m-1 && y==n-1) {
		cout << "success\n";
		v.push_back(cost+1);
		return ;
	}
	
	// 현재 위치는 visited로 마크한다.
	visited[y][x] = true;
	
	cout << "\n" << x << " " << y << "\n";
	// new pos를 계산한다.
	for(int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];

		cout << nx << " " << ny << "\n";
		if(nx<0 || ny<0 || nx>=n || ny>=m)
			continue;
		if(map[ny][nx] != 1 || visited[ny][nx] == true)
			continue;
		
		dfs(nx, ny, cost+1);
	}
}

int main(void) {
	cin >> n >> m;

	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<m; j++) {
			map[i][j] = s[j]-'0';
		}
	}

	dfs(0, 0, 0);

	// sort(v.begin(), v.end());
	// cout << v.back() << "\n";

	return 0;
}