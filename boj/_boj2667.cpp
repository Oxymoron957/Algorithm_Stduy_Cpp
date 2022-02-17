/*
단지번호붙이기
https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[25][25];
bool visited[25][25];
int houses;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector <int> v;

void dfs(int x, int y) {
	// 단지 내의 집의 갯수 증가
	houses += 1;

	// 도착한 곳 마크하기
	visited[x][y] = true;

	// next position을 계산하고 grid안에 있다면 & 방문하지 않았다면 재귀 호출
	for(int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];

		if(nx<0 || ny<0 || nx>=n || ny>=n)
			continue;
		if(visited[nx][ny] == 1 || arr[nx][ny] == 0)
			continue;
		
		dfs(nx, ny);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input 입력받기
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;

		for(int j=0; j<n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	// 각 pixel에 대하여 dfs 조사한 뒤에 카운드 편수 증가 && 갯수를 벡터 변수에 넣기 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				houses = 0;
				dfs(i, j);
				v.push_back(houses);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto e:v) {
		cout << e << "\n";
	}
	return 0;
}