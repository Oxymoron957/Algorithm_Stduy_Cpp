/*
스택
https://www.acmicpc.net/problem/10828
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	stack<int> st;
	while(n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int element;
			cin >> element;
			st.push(element);
		}
		else if (cmd == "top" && st.size() == 0) {
			cout << -1 << "\n";
		}
		else if (cmd == "top" && st.size() != 0) {
			cout << st.top() << "\n";
		}
		else if (cmd == "pop" && st.size() == 0) {
			cout << -1 << "\n";
		}
		else if (cmd == "pop" && st.size() != 0) {
			cout << st.top() << "\n";
			st.pop();
		}
		else if (cmd == "size") {
			cout << st.size() << "\n";
		}
		else if (cmd == "empty" && st.size() == 0) {
			cout << 1 << "\n";
		}
		else if (cmd == "empty" && st.size() != 0) {
			cout << 0 << "\n";
		}
	}
	return 0;
}