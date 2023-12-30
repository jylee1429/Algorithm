#include <stdio.h>
#include <stdlib.h>

int Compare(void* _a, void* _b) {
	int* a = (int*)_a;
	int* b = (int*)_b;

	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main(void) {
	int cnt, i;
	int arr[501];

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, cnt, sizeof(int), Compare);

	for (i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
