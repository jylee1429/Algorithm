#include <stdio.h>

int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main(void) {
	int n, i;
	int arr[1001];
	int dp[1001] = { 0 };

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	dp[2] = Max(arr[1], arr[2]);

	for (i = 3; i <= n; i++) {
		dp[i] = Max(dp[i - 1], dp[i - 2] + arr[i]);
	}

	printf("%d", dp[n]);


	return 0;
}
