/*
Quick Sorting 
분할 정복을 사용한 정렬 알고리즘

1. 피벗을 설정한다. (처음엔 첫번째 element를 보통 피벗으로 사용)
2. 피벗보다 큰 원소를 끝에서부터 찾는다.
3. 피벗보다 작은 원소를 시작에서부터 찾는다.
4. 작은 원소의 idx가 큰 원소의 idx보다 크다 : 작은 원소와 큰 원소를 swap한다.
5. 찾는 idx가 서로 엇갈릴 때까지 반복한다.
6. 피벗과 (피벗보다 큰 원소를 찾는 idx)와 바꾼다.
7. 옮겨진 피벗을 기준으로 왼쪽과 오른쪽에 분할정복 call 
*/

#include <iostream>

void quick_sort(int arr[], int start, int end);
void swap(int arr[], int idx1, int idx2);

int main(void){
	int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int size = 10;
	quick_sort(arr, 0, 9);
	for(auto e:arr){
		std::cout << e << ", ";
	}
	std::cout << "\n";
}

void quick_sort(int arr[], int start, int end){
	// 원소가 하나거나 논리적으로 맞지 않을 경우를 탈출 조건으로 
	if (start >= end)
		return ;
	// 피벗을 설정한다.
	int pivot = start;
	int i = start + 1;
	int j = end;

	// 엇갈리기 전까지 반복한다.
	while (i <= j)
	{
		// 피벗보다 작은 원소를 시작에서부터 찾는다.
		while (arr[pivot] >= arr[i] && i <= end)
			i += 1;
		// 피벗보다 큰 원소를 끝에서부터 찾는다. j == start일 때는 피벗이랑 같을 경우이므로 X
		while (arr[pivot] <= arr[j] && j > start)
			j -= 1;
		// 엇갈렸다면 피봇, j 교체
		if (i > j)
			swap(arr, pivot, j);
		// 아직 엇갈리지 않았다면 i, j 교체
		else
			swap(arr, i, j);
	}
	// 엇갈린 이후엔 옮겨진 pivot을 기준으로 분할정복 call
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
	return ;
}