#include <stdio.h>

int Min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int arr[30001] = { 0 };

int main(void) {
	int n, i;

	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;

		if (i % 2 == 0) {
			arr[i] = Min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = Min(arr[i], arr[i / 3] + 1);
		}
		if (i % 5 == 0) {
			arr[i] = Min(arr[i], arr[i / 5] + 1);
		}
	}

	printf("%d", arr[n]);

	return 0;
}
