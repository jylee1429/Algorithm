#include <bits/stdc++.h>
#define SIZE 300

using namespace std;

int n, m;
int ice[SIZE][SIZE];
int ice_copy[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Melt(void);
void Ice_Count(int a, int b);
void Init_Visited(void);

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			ice[i][j] = x;
		}
	}

	int year = 0;

	while (true) {
		int result = 0;
		Init_Visited();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && ice[i][j] != 0) {
					Ice_Count(i, j);
					result++;
				}
			}
		}

		if (result == 0) {
			printf("%d", 0);
			break;
		}
		else if (result >= 2) {
			printf("%d", year);
			break;
		}

		year++;
		Melt();
	}

}

void Melt(void) {
	for (int i = 0; i < n; i++) {
		fill_n(ice_copy[i], SIZE, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i;
			int y = j;
			int cnt = 0;

			if (ice[x][y] == 0)
				continue;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (ice[nx][ny] == 0)
					cnt++;
			}

			ice_copy[x][y] = ice[x][y] - cnt;
			if (ice_copy[x][y] < 0)
				ice_copy[x][y] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ice[i][j] = ice_copy[i][j];
		}
	}
}

void Ice_Count(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (ice[nx][ny] != 0 && visited[nx][ny] == false) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	 }
}

void Init_Visited(void) {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], SIZE, false);
	}
}
