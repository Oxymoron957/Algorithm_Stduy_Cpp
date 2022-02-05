/*
Heap Sort 
- 배열을 완전 이진 트리로 표현한다. (차례대로 채워진다.)
- Heap 생성 알고리즘을 통해 Max Heap Tree를 구성한다. (부모 노드가 언제나 자식 노드보다 크다.)
- Root Node의 있는 원소를 가장 말단 노드와 바꾸고 정렬된 상태로 고정한다.
- 다시 Heapify 알고리즘을 적용한다.
- 이하 반복

Heapify Algorithm
- 트리에 하나의 노드를 제외하고 최대 힙이 구성되어있다고 가정한다.
- 특정한 노드의 두 자식 중에서 더 큰 자식과 자신의 위치를 바꾼다. 
	-> 바꾸고 난 뒤에도 자식이 존재하는 경우 같은 연산을 반복한다. -> 자식이 더 이상 존재하지 않을 때 까지
*/

#include <iostream>

void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
	return ;
}

int main(void) {
	int size = 9;
	int arr[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

	// Heapify Algorithm
	for(int i = 1; i < size; i++) {
		int current_node = i; // current node를 정한다.
		do {
			int local_root = (current_node-1)/2; // current node의 root node를 정한다.

			if (arr[local_root] < arr[current_node]) // current node가 root node보다 더 크다면 swap
				swap(arr, local_root, current_node);
				
			current_node = local_root; // root를 새로운 current 노드로 설정한다. (한 레벨 거슬러 올라간다.)
		} while (current_node != 0); // current node가 root node일 때가지
	}

	// Heap 정렬하기
	for (int i = size-1; i >= 0; i--) { // 크기를 점점 줄여나간다.
		swap(arr, 0, i); // 말단 노드와 root 노드 swap

		int local_root = 0;
		int current_node = 1;

		do {		 
			// local root의 두 자식 중 큰 것으로 선택 
			if (current_node < i-1 && arr[current_node] > arr[current_node+1])
				current_node = 2*local_root+2;
			else
				current_node = 2*local_root+1;
			
			// local root보다 current node가 더 크다면 swap
			if (current_node < i && arr[local_root] < arr[current_node])
				swap(arr, local_root, current_node);

			local_root = current_node; // 한 단계 더 내려간다. 
		} while(current_node < i); // local root의 자식이 끝에 도달할 때까지 
	}

	for (auto e:arr) {
		std::cout << e << " "; 
	}
	std::cout << "\n";
	return 0;
}