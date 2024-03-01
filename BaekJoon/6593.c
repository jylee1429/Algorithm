#include <bits/stdc++.h>

using namespace std;

typedef struct _array {
	char arr[31][31];
}Arr;
typedef struct _array_int_ {
	int arr_int[31][31];
}Arr_Int;

int l, r, c;
int start_x, start_y, start_z;
int end_x, end_y, end_z;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

Arr building[31];
Arr_Int building_copy[31];

int BFS(int x, int y, int z);
void Fill_Building(void);

int main(void) {
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					char x;
					cin >> x;
					building[i].arr[j][k] = x;
					if (x == 'S') {
						start_x = j;
						start_y = k;
						start_z = i;
					}
					if (x == 'E') {
						end_x = j;
						end_y = k;
						end_z = i;
					}
				}
			}
		}
		
		Fill_Building();

		int result = BFS(start_x, start_y, start_z);
		if (result) {
			cout << "Escaped in " << result - 1 << " minute(s)." << "\n";
		}
		else {
			cout << "Trapped!" << "\n";
		}
	}
}

// x:행, y:열, z:층
int BFS(int x, int y, int z) {
	// <x,y>,z
	queue<pair<pair<int, int>, int>> q;

	q.push({ {x,y},z });
	building_copy[z].arr_int[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			if (building_copy[nz].arr_int[nx][ny] <= 0 && building[nz].arr[nx][ny] != '#') {
				q.push({ {nx,ny},nz });
				building_copy[nz].arr_int[nx][ny] = building_copy[z].arr_int[x][y] + 1;
			}
		}
	}

	return building_copy[end_z].arr_int[end_x][end_y];
}

void Fill_Building(void) {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			fill_n(building_copy[i].arr_int[j], 31, 0);
		}
	}
}
