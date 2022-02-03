/*
수 정렬하기
https://www.acmicpc.net/problem/2750
*/

#include <iostream>

int main(void){
	int n;
	std::cin >> n;

	int arr[1001] = {};
	for(int i=0; i<n; i++){
		std::cin >> arr[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\n";
	}
	return 0;
}