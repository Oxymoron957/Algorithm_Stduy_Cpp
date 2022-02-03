/*
Merge Sorting : 일단 반으로 나누고 나중에 합쳐서 정렬하면 어떨까?
*/

#include <iostream>

int buffer[8]; // 정렬된 배열을 임시로 담는 버퍼의 크기는 원본 배열의 크기만큼 커야한다.

void merge_sort(int arr[], int m, int n);
void merge(int arr[], int m, int middle, int n);

int main(void){
	int arr[] = {7, 6, 5, 8, 3, 5, 9, 1};
	merge_sort(arr, 0, 7);
	for(int i=0; i<8; i++){
		if (i != 0)
			std::cout << ",";
		std::cout << arr[i];
	}
	std::cout << "\n";
}

// 반으로 계속 쪼개서 recursive call & 가장 작아진 m, n을 정렬한다.
void merge_sort(int arr[], int m, int n){
	if(m < n){ // 엇갈리기 전에
		int middle = (m+n)/2; // 일단 반으로 자른다.
		
		merge_sort(arr, m, middle); // 자른 idx에 대해 recursive call
		merge_sort(arr, middle+1, n);
		
		merge(arr, m, middle, n); // m~middle와 middle~n을 정렬해서 합친다. 
	}
}

// 이미 정렬된 m~middle와 middle~n을 합친다. 
void merge(int arr[], int m, int middle, int n){
	int i = m; // i : m ~ middle
	int j = middle + 1; // j : middle+1 ~ n
	int k = m; // k : m ~ n

	// i, j 둘다 range안에서 
	while (i <= middle && j <= n){
		// 작은 것부터 buffer[k]에 넣는다.
		if (arr[i] <= arr[j]){ 
			buffer[k] = arr[i];
			i += 1;
		}
		else {
			buffer[k] = arr[j];
			j += 1;
		}
		k += 1;
	}
	if (i > middle) // j가 아직 range안에 있을때 j안의 값을 다 넣는다.
		for (int t = j; t <= n; t++){
			buffer[k] = arr[t];
			k += 1;
		}
	else // i가 아직 range안에 있을때 i안의 값을 다 넣는다.
		for (int t = i; t <= m; t++){
			buffer[k] = arr[t];
			k += 1;
		}
	// 정렬된 결과를 원본 배열에 넣는다.
	for(int t = m; t <= n; t++){
		arr[t] = buffer[t];
	}
}