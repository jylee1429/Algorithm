#include <stdio.h>

typedef struct _point {
	int x;
	int y;
}Point;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
char move_types[4] = { 'R', 'U', 'L', 'D' };

int main(void) {
	int size, i, j, nx, ny;
	char routine[100];

	Point point;
	point.x = 1;
	point.y = 1;

	scanf("%d", &size);
	scanf("%s", routine);

	for(i = 0; routine[i] != '\0'; i++){
		for (j = 0; j < 4; j++) {
			if (routine[i] == move_types[j]) {
				nx = point.x + dx[j];
				ny = point.y + dy[j];
			}
		}

		if (nx < 1 || ny < 1 || nx > size || ny > size)
			continue;

		point.x = nx;
		point.y = ny;
	}

	printf("%d %d", point.y, point.x);

	return 0;
}
