#include <stdio.h>

int map[51][51] = { -1 };
int reached_map[51][51] = { 0 };

// 북, 동, 남, 서
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,-1,0 };
int dir;											   // 0 : 북, 1 : 동, 2 : 남, 3 : 서

void Dir_Change(void) {
	dir -= 1;
	if (dir == -1)
		dir = 3;
}

int main(void) {
	int size_x, size_y;
	int pos_x, pos_y;							 
 	int i, j;
	int cnt = 0, turn = 0;

	scanf("%d %d", &size_x, &size_y);
	scanf("%d %d %d", &pos_x, &pos_y, &dir);
	for (i = 0; i < size_y; i++) {
		for (j = 0; j < size_x; j++) {
			scanf("%d", &map[i][j]);					// 1 : 바다, 0 : 육지
		}
	}

	while (1) {
		Dir_Change();
		int nx = pos_x + dx[dir];
		int ny = pos_y + dy[dir];
		// 육지이고 가보지 않은 곳인 경우
		if (map[nx][ny] == 0 && reached_map[nx][ny] == 0) {
			reached_map[nx][ny] = 1;
			pos_x = nx;
			pos_y = ny;
			cnt++;
			turn = 0;
			continue;
		}
		// 회전한 후에 바다이거나 가본 곳인 경우
		else {
			turn++;
		}
		// 회전을 4번 한 경우(이동하지 못하는 경우)
		if (turn == 4) {
			nx = pos_x - dx[dir];
			ny = pos_y - dy[dir];
			// 뒤로 갔을때 육지인 경우
			if (map[nx][ny] == 0) {
				pos_x = nx;
				pos_y = ny;
				turn = 0;
			}
			else
				break;
		}
	}

	printf("%d", cnt);
	
	return 0;
}
