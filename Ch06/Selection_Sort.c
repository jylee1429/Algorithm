#include <stdio.h>

void Swap(int* a, int* b);

int main(void) {
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };
	int i, j, size;

	size = sizeof(arr) / sizeof(arr[0]);
	
	for (i = 0; i < size; i++) {
		int min_index = i;
		for (j = i + 1; j < size; j++) {
			if (arr[min_index] > arr[j])
				min_index = j;
		}
		Swap(&arr[min_index], &arr[i]);
	}

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
