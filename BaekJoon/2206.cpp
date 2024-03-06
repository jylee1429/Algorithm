#include<bits/stdc++.h>
#define SIZE 1001

using namespace std;  

int n, m;
int graph[SIZE][SIZE];
int visited[SIZE][SIZE][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS(int a, int b);

int main(void) {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%1d", &x);
			graph[i][j] = x;
		}
	}


	int result = BFS(1, 1);
	cout << result;
}

int BFS(int a, int b) {
	queue < pair<int, pair<int, int>>> q;

	q.push({ 1,{a,b} });
	visited[a][b][1] = 1;

	while (!q.empty()) {
		int block = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		// 목표 지점에 도착했을 경우
		if (x == n && y == m) {
			return visited[x][y][block];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m)
				continue;
			
			if (graph[nx][ny] == 1 && block == 1) {
				visited[nx][ny][block-1] = visited[x][y][block] + 1;
				q.push({ 0,{nx,ny} });
			}
			else if (graph[nx][ny] == 0 && visited[nx][ny][block] == 0) {
				visited[nx][ny][block] = visited[x][y][block] + 1;
				q.push({ block,{nx,ny} });
			}
		}
	}

	return -1;
}
