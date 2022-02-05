/*
알파벳 개수
https://www.acmicpc.net/problem/10808
*/

#include <iostream>

using namespace std;

int main(void) {
	int arr['z'-'a'+1] = {0};
	string s;
	cin >> s;
	for(auto c: s)
		arr[(char)c-'a']++;
	for(auto e:arr)
		cout << e << " ";
	cout << "\n";
	return 0;
}
