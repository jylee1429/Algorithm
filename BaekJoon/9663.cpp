#include <bits/stdc++.h>
#define SIZE 15
using namespace std;

int n;
int cnt = 0;
int columns[SIZE];

void DFS(int row);
bool Check_Queen(int row);

int main(void) {
	cin >> n;

	DFS(0);
	cout << cnt;
}

void DFS(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		columns[row] = i;

		if (Check_Queen(row)) {
			DFS(row + 1);
		}
	}
}
bool Check_Queen(int row) {
	for (int i = 0; i < row; i++) {
		// 수직인 경우
		if (columns[row] == columns[i])
			return false;
		if (abs(row - i) == abs(columns[row] - columns[i]))
			return false;
	}

	return true;
}
