#include <stdio.h>

typedef struct _point {
	int row;
	int calumn;
}Point;

int steps[8][2] = {
	{-2, -1},
	{-1, -2},
	{1, -2},
	{2, -1},
	{2, 1},
	{1, 2},
	{-1, 2},
	{-2, 1}
};

int main(void) {
	Point point;
	char calumn;    // 열
	int row;		// 행
	int i, cnt = 0;

	scanf("%c", &calumn);
	scanf("%d", &row);
	// 위치
	point.calumn = calumn - 96;
	point.row = row;
	
	for (i = 0; i < 8; i++) {
		int next_row = point.row + steps[i][0];
		int next_calumn = point.calumn + steps[i][1];

		if (next_row >= 1 && next_row <= 8 && next_calumn >= 1 && next_calumn <= 8)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}
