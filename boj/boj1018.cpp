/*
체스판 다시 칠하기
https://www.acmicpc.net/problem/1018
*/

#include <iostream>
#include <vector>
using namespace std;

int m, n;
char board[51][51];
vector<int> vec;
int x, y;

int check(int row, int col, char standard) {
	int count = 0;
	int cur_r = row;
	int cur_c = col;
	char theother = 0;
	if (standard == 'W')
		theother = 'B';
	else
		theother = 'W';

	while (cur_r < row+8)
	{
		cur_c = 0;
		while (cur_c < col+8){
			// cout << cur_r << " " << cur_c << " ";
			if (cur_r % 2 == 0 && cur_c % 2 == 0)
				if (board[cur_r][cur_c] != standard)
					count += 1;
			if (cur_r % 2 == 0 && cur_c % 2 == 1)
				if (board[cur_r][cur_c] != theother)
					count += 1;
			if (cur_r % 2 == 1 && cur_c % 2 == 0)
				if (board[cur_r][cur_c] != theother)
					count += 1;
			if (cur_r % 2 == 1 && cur_c % 2 == 1)
				if (board[cur_r][cur_c] != standard)
					count += 1;
			cur_c += 1;
		}
		cur_r += 1;
	}
	cout << count << "\n"; 
	return count;
}

int main(void) {
	cin >> m >> n;
	for (int i=0; i<m;i++) {
		string s;
		cin >> s;
		for (int j=0; j<n; j++)
			board[i][j] = s[j];
	}

	// cout << "\n";
	// for (int i=0; i<m;i++) {
	// 	for (int j=0; j<n; j++)
	// 		cout << board[i][j];
	// 	cout << "\n";
	// }

	int row = 0;
	int col = 0;

	while (row+8 < m)
	{
		col = 0;
		while (col+8 < n)
		{
			// cout << row << " " << col << "\n";
			vec.push_back(check(row, col, 'W'));
			vec.push_back(check(row, col, 'B'));
			col += 1;
		}
		row += 1;
	}
	
	return 0;
}