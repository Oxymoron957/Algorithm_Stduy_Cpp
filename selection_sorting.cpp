/*
Selection sorting
: 가장 작은 것을 선택해서 제일 앞으로 보내는 정렬 알고리즘
*/

#include <iostream>

void selection_sorting(int arr[], int size);
void swap(int arr[], int idx1, int idx2);

int main(void){
    int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	selection_sorting(arr, 10);
	for(auto element : arr)
	{
		std::cout << element << ", ";
	}
	std::cout << "\n";
	return 0;
}

void selection_sorting(int arr[], int size){
    int local_min = INT_MAX;
    int local_min_idx = 0;

    for(int i = 0; i < size; i++){
		local_min = arr[i];
        for(int j = i+1; j < size; j++){
            if (local_min > arr[j]){
				local_min = arr[j];
				local_min_idx = j;
            }
        }
		swap(arr, local_min_idx, i);
	}
	return ;
}

void swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;

	return;
}