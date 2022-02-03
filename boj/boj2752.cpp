/*
세수정렬
https://www.acmicpc.net/problem/2752
*/

#include <iostream>

int main(void){
	int arr[3] = {};
	std::cin >> arr[0] >> arr[1] >> arr[2];

	for(int i=0; i<3; i++){
		for(int j=i; j<3; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
	return 0;
}