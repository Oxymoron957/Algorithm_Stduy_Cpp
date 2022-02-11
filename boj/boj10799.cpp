/*
쇠막대기
https://www.acmicpc.net/problem/10799
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string s;
	int answer = 0;
	cin >> s;

	stack<char> st;
	for(int i=0; i<s.size(); i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else if (s[i] == ')') {
			st.pop();
			if (s[i-1] == '(')
				answer += st.size();
			else
				answer += 1;
		}
	}
	cout << answer << "\n";
	return 0;
}