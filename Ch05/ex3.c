#include <stdio.h>
#define SIZE 1000
#define TRUE 1
#define FALSE 0

int DFS(int start_x, int start_y);

int graph[SIZE + 1][SIZE + 1];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int cnt = 0;

int main(void) {
	int i, j, k;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if(DFS(i, j) == TRUE)
				cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}

int DFS(int start_x, int start_y) {
	int i;

	if (start_x < 1 || start_x > n || start_y < 1 || start_y > m)
		return FALSE;

	if (graph[start_x][start_y] == 0) {
		graph[start_x][start_y] = 1;
		DFS(start_x + 1, start_y);
		DFS(start_x, start_y + 1);
		DFS(start_x - 1, start_y);
		DFS(start_x, start_y - 1);

		return TRUE;
	}
	else
		return FALSE;

}

