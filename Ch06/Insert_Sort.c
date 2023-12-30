#include <stdio.h>
void Swap(int* a, int* b);

int main(void) {
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };
	int i, j;
	int size = sizeof(arr) / sizeof(arr[0]);

	for (i = 1; i < size; i++) {
		for (j = i; j > -1; j--) {
			if (arr[j] < arr[j - 1])
				Swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
	}

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	return 0;
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
