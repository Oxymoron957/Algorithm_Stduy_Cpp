/*
덱
https://www.acmicpc.net/problem/å
*/

#include <iostream>
#include <deque>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	deque <int> dq;

	for(int i=0; i<N; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int input;
			cin >> input;
			dq.push_front(input);
		}
		else if (cmd == "push_back") {
			int input;
			cin >> input;
			dq.push_back(input);
		}
		else if (cmd == "pop_front") {
			if (dq.size() != 0) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "pop_back") {
			if (dq.size() != 0) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << "\n";
		}
		else if (cmd == "empty") {
			if (dq.size() == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if(cmd == "front") {
			if (dq.size() != 0) {
				cout << dq.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (cmd == "back") {
			if (dq.size() != 0) {
				cout << dq.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}