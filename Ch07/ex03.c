#include <stdio.h>
#include <stdlib.h>

int arr[1000000];


int main(void) {
	int n, length;
	int i, mid, result;
	int max = 0, min = 0, sum = 0;

	scanf("%d", &n);
	scanf("%d", &length);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}

	while (min <= max) {
		sum = 0;
		mid = (max + min) / 2;
		for (i = 0; i < n; i++) {
			if(arr[i] > mid)
				sum += (arr[i] - mid);
		}

		// 떡의 양이 부족한 경우
		if (sum < length)
			max = mid - 1;
		// 떡의 양이 충분한 경우
		else {
			result = mid;
			min = mid + 1;
		}
	}

	printf("%d", result);

	return 0;
}
