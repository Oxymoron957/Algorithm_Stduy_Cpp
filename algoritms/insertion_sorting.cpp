/*
insertion sorting : 각 숫자를 필요할 때만 적절한 위치에 삽입하는 정렬 알고리즘
이미 정렬되어있는 자료구조에서 빠르다.
0~i-1번째 까지 정렬되어있다고 가정 -> i번째 원소가 어디에 들어가야할지 결정하면 된다.
*/

#include <iostream>

void insertion_sorting(int arr[], int size);
void swap(int arr[], int idx1, int idx2);

int main(void){
	int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int size = 10;
	insertion_sorting(arr, size);
	for(auto e:arr){
		std::cout << e << ", ";
	}
	std::cout << "\n";
	return 0;
}

void insertion_sorting(int arr[], int size){
	
	for(int i = 0; i < size; i++){
		int j = i;
		// (j+1)th element를 0~ith element의 적절한 위치에 넣는다. 
		// 만약 i+1까지 정렬되어 있다면 swap이 일어나지 않기 때문에 효율적이다!
		while (j >= 0 && arr[j] > arr[j + 1]){ 
			swap(arr, j, j + 1); 
			j -= 1;
		}
	}
}

void swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
	return ;
}