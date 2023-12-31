#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int arr_n[1000000];
int arr_m[100000];

int Compare(void* _a, void* _b);
int Binary_Search(int arr[], int start, int end, int target);

int main(void) {
	int n, m;
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr_n[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &arr_m[i]);

	qsort(arr_n, n, sizeof(int), Compare);
	

	for (i = 0; i < m; i++) {
		if (Binary_Search(arr_n, 0, n, arr_m[i]))
			printf("yes\t");
		else
			printf("no\t");
	}

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

int Binary_Search(int arr[], int start, int end, int target) {
	int mid = (start + end) / 2;

	if (start > end)
		return FALSE;

	if (arr[mid] == target)
		return TRUE;
	else if (arr[mid] > target)
		return Binary_Search(arr, start, mid - 1, target);
	else
		return Binary_Search(arr, mid + 1, end, target);
}
