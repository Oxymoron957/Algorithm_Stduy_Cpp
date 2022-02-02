/*
bubble sorting : 가까이에 있는 원소와 비교하여 조건 만족시에 swap하는 정렬 알고리즘
제일 간단하지만 제일 느리다.
*/

#include <iostream>

void bubble_sorting(int arr[], int size);
void swap(int arr[], int idx1, int idx2);

int main(void){
	int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int size = 10;
	bubble_sorting(arr, size);
	for(auto e:arr){
		std::cout << e << ", ";
	}
	std::cout << "\n";
	return 0;
}

void bubble_sorting(int arr[], int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i] > arr[j]){
				swap(arr, i, j);
			}
		}
	}
	return ;
}

void swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
	return ;
}