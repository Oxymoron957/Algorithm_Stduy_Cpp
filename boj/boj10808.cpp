/*
알파벳 개수
https://www.acmicpc.net/problem/10808
*/

#include <iostream>

using namespace std;

int func2(int arr[], int N);

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

/*
연습문제
주어진 배열의 합이 100인 두 원소가 존재하면서 1을, 없다면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라
*/

// O(n^2) 풀이
int func2(int arr[], int N) {
	for (int i=0; i<N; i++)
		for (int j=i; j<N; j++) 
			if (arr[i] + arr[j] == 100)
				return 1;
	return 0;
}

int num_app[101];
int func2(int arr[], int N) {
	for (int i=0; i<N; i++){
		if (num_app[100-arr[i]] == 1)
			return 1;
		num_app[arr[i]] = 1;
	}
	return 0;
}

