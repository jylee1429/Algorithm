#include <stdio.h>

void Quick_Sort(int arr[], int start, int end);
void Swap(int* a, int* b);

int main(void) {
	int arr[10] = { 5,7,9,0,3,1,6,2,4,8 };
	int i;

	Quick_Sort(arr, 0, 9);

	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void Quick_Sort(int arr[], int start, int end) {
	
	int pivot = start;
	int left = start + 1;
	int right = end;

	// 배열의 원소가 1개인 경우
	if (start >= end)
		return;
	
	while (left <= right) {
		// pivot보다 큰 데이터 찾기
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		// pivot보다 작은 데이터 찾기
		while (right > start && arr[right] >= arr[pivot])
			right--;
		// 엇갈릴 경우
		if (left > right)
			Swap(&arr[right], &arr[pivot]);
		else
			Swap(&arr[right], &arr[left]);
	}
	Quick_Sort(arr, start, right - 1);
	Quick_Sort(arr, right + 1, end);
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
