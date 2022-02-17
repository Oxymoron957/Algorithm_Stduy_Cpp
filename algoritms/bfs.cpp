/*
BFS : Queue와 Pair 자료구조를 이용하여 FIFO의 특성을 활용한 탐색을 실시한다.
*/

#include <iostream>
#include <queue>
// #include <utility>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool visited[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	// 입출력 속도를 위한 코드
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Queue 생성 및 초기화
	queue<pair<int, int>> Q;
	visited[0][0] = 1;
	Q.push({0, 0});
	
	// 대기열이 없어질 때까지 반복
	while (!Q.empty()) {
		// 현재 위치 pop & 저장 & 출력
		pair<int, int> cur = Q.front(); 
		Q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") ->";

		// next position 계산
		for(int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			// next position이 grid 밖으로 나가면 continue
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			// next position이 이미 방문했거나 갈 수 없는 지역이면 continue
			if (visited[nx][ny] || board[nx][ny] != 1)
				continue ; 
			
			// next postion을 방문한 것으로 기록하고 queue에 push 
			visited[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
	
	return 0;
}