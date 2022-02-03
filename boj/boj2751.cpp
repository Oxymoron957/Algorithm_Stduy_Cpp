/*
수 정렬하기 2
https://www.acmicpc.net/problem/2751
*/

#include <iostream>
#include <algorithm>

int main(void){
	int n = 0;
	std::cin >> n;

	int arr[1000000] = {};
	for(int i=0; i<n; i++){
		std::cin >> arr[i];
	}
	std::sort(arr, arr+n);
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\n";
	}
}
