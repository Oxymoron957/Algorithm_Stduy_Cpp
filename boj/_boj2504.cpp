/*
괄호의 값
https://www.acmicpc.net/problem/2504

tip : 괄호에 관한 문제는 i와 i-1의 인덱스를 사용해서 () or []를 감지하자
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	int answer = 0;
	int local = 1;
	stack<char> st;

	for(int i=0; i<s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			local *= 2;
		}
		else if (s[i] == '[') {
			st.push(s[i]);
			local *= 3;
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				answer = 0;
				break ;
			}

			if (s[i-1] == '(') {
				answer += local;
				local /= 2;
				st.pop();
			}
			else {
				local /= 2;
				st.pop();
			}
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[') {
				answer = 0;
				break ;
			}

			if (s[i-1] == '[') {
				answer += local;
				local /= 3;
				st.pop();
			}
			else {
				local /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty()) {
		cout << "0\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}