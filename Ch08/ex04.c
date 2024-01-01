#include <stdio.h>
#include <math.h>

#define NUM 796796

int main(void) {
	int n, i;
	int arr[1001];

	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 3;
	for (i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] * 2;
	}

	printf("%d", arr[n] % NUM);

	return 0;
}
