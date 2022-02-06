/*
큐
https://www.acmicpc.net/problem/10845
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ini_input = 0;
	cin >> ini_input;
	queue<int> q;
	while(ini_input--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (cmd == "pop" && q.size() != 0) {
			cout << q.front() << "\n";
			q.pop();
		}
		else if (cmd == "pop" && q.size() == 0) {
			cout << -1 << "\n";
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty" && q.size() == 0) {
			cout << "1" << "\n";
		}
		else if (cmd == "empty" && q.size() != 0) {
			cout << "0" << "\n";
		}
		else if (cmd == "front" && q.size() != 0) {
			cout << q.front() << "\n";
		}
		else if (cmd == "front" && q.size() == 0) {
			cout << "-1\n";
		}
		else if (cmd == "back" && q.size() != 0) {
			cout << q.back() << "\n";
		}
		else if (cmd == "back" && q.size() == 0) {
			cout << "-1\n";
		}
	}
	return 0;
}