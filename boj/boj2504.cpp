/*
괄호의 값
https://www.acmicpc.net/problem/2504
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	int answer = 0;
	int local = 0;
	stack<char> st;
	for(int i=0; i<s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			answer += local;
			local = 0;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.top() != '(') {
				cout << "0\n";
				return 0;
			}
			else {
				if (local == 0)
					local += 2;
				else 
					local *= 2;
				st.pop();
			}
		}
		else if (s[i] == ']') {
			if (st.top() != '[') {
				cout << "0\n";
				return 0;
			}
			else {
				if (local == 0)
					local += 3;
				else 
					local *= 3;
				st.pop();
			}
		}
	}
	cout << answer << "\n";
	return 0;
}