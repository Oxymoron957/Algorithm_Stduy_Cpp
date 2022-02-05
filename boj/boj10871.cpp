/*
X보다 작은 수
https://www.acmicpc.net/problem/10871
*/

#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;

	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		if (num < x) {
			cout << num << " ";
		}
	}
	cout << "\n";
	return 0;
}