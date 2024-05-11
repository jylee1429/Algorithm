#include <iostream>

#define SIZE 10

using namespace std;

int t;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int graph[SIZE][SIZE];

int main(void) {
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		int cx = 0, cy = 0, dir = 0;

		scanf("%d", &n);
		printf("#%d\n", c + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				graph[i][j] = 0;
		}

		graph[cx][cy] = 1;

		while (graph[cx][cy] < n * n) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || graph[nx][ny] != 0) {
				dir += 1;
				if (dir == 4)
					dir = 0;
				continue;
			}

			graph[nx][ny] = graph[cx][cy] + 1;
			cx = nx;
			cy = ny;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", graph[i][j]);
			}
			printf("\n");
		}
	}
}
