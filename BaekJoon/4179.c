#include <bits/stdc++.h>
#define SIZE 1001

using namespace std;

int n, m;
int start_x, start_y;
int maze_fire[SIZE][SIZE];
int maze_person[SIZE][SIZE];
char maze[SIZE][SIZE];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> qf;
queue<pair<int, int>> qp;

void Spread_Fire(void);
void Fill_Maze(void);
int Move_Person(int a, int b);

int main(void) {
	cin >> n >> m;
	Fill_Maze();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == 'F') {
				qf.push({ i,j });
				maze_fire[i][j] = 0;
			}
			if (x == 'J') {
				start_x = i;
				start_y = j;
			}
			maze[i][j] = x;
		}
	}

	Spread_Fire();
	int result = Move_Person(start_x, start_y);
	if (result == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << result + 1;
	}

}

void Spread_Fire(void) {
	while (!qf.empty()) {
		int x = qf.front().first;
		int y = qf.front().second;
		qf.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (maze_fire[nx][ny] >= 0 || maze[nx][ny] == '#') {
				continue;
			}
			maze_fire[nx][ny] = maze_fire[x][y] + 1;
			qf.push({ nx,ny });
		}
	}
}

void Fill_Maze(void) {
	for (int i = 0; i < SIZE; i++) {
		fill_n(maze_fire[i], SIZE, -1);
	}
	for (int i = 0; i < SIZE; i++) {
		fill_n(maze_person[i], SIZE, -1);
	}
}

int Move_Person(int a, int b) {
	qp.push({ a,b });
	maze_person[a][b] = 0;

	while (!qp.empty()) {
		int x = qp.front().first;
		int y = qp.front().second;
		qp.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				return maze_person[x][y];
			}
			// 방문한 적이 있거나 벽인 경우
			if (maze_person[nx][ny] >= 0 || maze[nx][ny] == '#') {
				continue;
			}
			// 불이 있는 곳이거나 불이 먼저 확산하는 곳인 경우
			if (maze_fire[nx][ny] != -1 && maze_fire[nx][ny] <= maze_person[x][y] + 1) {
				continue;
			}

			maze_person[nx][ny] = maze_person[x][y] + 1;
			qp.push({ nx,ny });
		}
	}

	return -1;
}
