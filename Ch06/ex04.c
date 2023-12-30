#include <stdio.h>
#include <stdlib.h>

int arr1[100001];
int arr2[100001];

int Compare(void* _a, void* _b);
void Swap(int* a, int* b);

int main(void) {
	int cnt, chance;
	int i, sum = 0;

	scanf("%d %d", &cnt, &chance);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < cnt; i++) {
		scanf("%d", &arr2[i]);
	}

	qsort(arr1, cnt, sizeof(int), Compare);
	qsort(arr2, cnt, sizeof(int), Compare);
	
	for (i = 0; i < chance; i++) {
		if (arr1[i] < arr2[cnt - i - 1])
			Swap(&arr1[i], &arr2[cnt - i - 1]);
		else
			break;
	}
	
	for (i = 0; i < cnt; i++) {
		sum += arr1[i];
	}

	printf("%d", sum);

	return 0;
}

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

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
