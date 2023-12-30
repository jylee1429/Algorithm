#include <stdio.h>

int graph[201][201];
int queue[201][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void) {
	int n, m, nx, ny;
	int i, j;
	int pop_x, pop_y;
	int rear = 0, front = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	queue[rear][0] = 1;
	queue[rear][1] = 1;

	rear++;

	while (front < rear) {
		pop_x = queue[front][0];
		pop_y = queue[front][1];
		front++;

		for (i = 0; i < 4; i++) {
			nx = pop_x + dx[i];
			ny = pop_y + dy[i];
			// 범위를 벗어난 경우
			if (nx<1 || nx>n || ny<1 || ny>m)
				continue;
			// 벽인 경우
			if (graph[nx][ny] == 0)
				continue;
			// 노드를 방문하는 경우
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[pop_x][pop_y] + 1;
				queue[rear][0] = nx;
				queue[rear][1] = ny;
				rear++;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d", graph[n][m]);

	return 0;
}
