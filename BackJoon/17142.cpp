#include <bits/stdc++.h>
#define SIZE 50
#define INF 1e9

using namespace std;

int n, m;
int result = INF;
int labotary[SIZE][SIZE];
int labotary_copy[SIZE][SIZE];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> virus;

int BFS(queue<pair<int, int>> q);
int Labotary_Check(void);

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> labotary[i][j];
			if (labotary[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	
	vector<bool> temp(virus.size());
	fill_n(temp.begin(), m, true);
	sort(temp.begin(), temp.end());

	do {
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				labotary_copy[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
		
				if (labotary[i][j] == 1) {
					// 벽
					labotary_copy[i][j] = -1;
				}
				else {
					labotary_copy[i][j] = labotary[i][j];
				}
			}
		}

		for (int i = 0; i < temp.size(); i++) {
			int x = virus[i].first;
			int y = virus[i].second;

			if (temp[i]) {
				// 활성 바이러스 
				labotary_copy[x][y] = -2;
				q.push({ x,y });
			}
			else {
				// 비활성 바이러스
				labotary_copy[x][y] = -3;
			}
		}

		int min_val = BFS(q);
		
		if (min_val == -1)
			continue;
		else {
			if (min_val < result) {
				result = min_val;
			}
		}

	} while (next_permutation(temp.begin(), temp.end()));
	
	if (result == INF)
		cout << -1;
	else
		cout << result;
}

int BFS(queue<pair<int, int>> q) {
	int cnt = 0;

	while (!q.empty()) {
		int size = q.size();

		cnt++;
		for (int i = 0; i < size; i++) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					continue;
				}
				if (labotary_copy[nx][ny] == -1 || labotary_copy[nx][ny] == -2) {
					continue;
				}
				if (labotary_copy[nx][ny] == -3) {
					labotary_copy[nx][ny] = -2;
					q.push({ nx,ny });
				}
				if (labotary_copy[nx][ny] == 0) {
					labotary_copy[nx][ny] = cnt;
					q.push({ nx,ny });
				}
			}
		}
	}
	
	int result = Labotary_Check();

	return result;
}

int Labotary_Check(void) {
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!labotary_copy[i][j]) {
				return -1;
			}
			if (labotary_copy[i][j]) {
				if (max < labotary_copy[i][j])
					max = labotary_copy[i][j];
			}
		}
	}

	return max;
}
