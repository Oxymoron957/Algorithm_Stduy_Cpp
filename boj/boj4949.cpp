/*
균형잡힌 세상
https://www.acmicpc.net/problem/4949
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string check(stack<char> &st, string &s) {
	for(int i=0; i<s.length(); i++) {
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == ']') {
			if (st.empty()) {
				return "no\n";

			}
			else if(st.top() == '(' && s[i] == ']') {
				return "no\n";
			}
			else if(st.top() == '[' && s[i] == ')') {
				return "no\n";
			}
			else if(st.top() == '(' && s[i] == ')') {
				st.pop();
			}
			else if(st.top() == '[' && s[i] == ']') {
				st.pop();
			}
		}	
	}
	if (st.size() == 0)
		return "yes\n";
	else 
		return "no\n";
}

int main(void) {
	string s;
	getline(cin, s);
	while (s != ".")
	{
		stack <char> st;
		cout << check(st, s);
		getline(cin, s);
	}
	
	return 0;
}