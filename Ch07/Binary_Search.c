#include <stdio.h>

int Binary_Search(int arr[], int start, int end);

int main(void) {
	int arr[10] = { 2, 4, 6,8,10,12,14,16,18.20 };
	int target = 7;
	int target_index;

	target_index = Binary_Search(arr, target, 0, 9);
	if (target_index == -1)
		printf("탐색 대상이 존재하지 않습니다.");
	else
		printf("탐색 대상 위치 : %d", target_index);

	return 0;
}

int Binary_Search(int arr[], int target, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return Binary_Search(arr, target, start, mid - 1);
	else
		return Binary_Search(arr, target, mid + 1, end);
	return -1;
}

