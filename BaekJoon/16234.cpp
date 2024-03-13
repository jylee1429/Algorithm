#include<bits/stdc++.h>
#include <thread>
#define SIZE 50

using namespace std;

int n,l,r;
int union_cnt = 0;
int year = 0;
int graph[SIZE][SIZE];
int visited[SIZE][SIZE];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> v;

void Border_Opening(int a, int b);
int Get_Union_Population(vector<pair<int, int>> v);
bool Check_Union(void);
void Visited_Init(void);

int main(void) {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			graph[i][j] = x;
		}
	}
	// 모든 나라의 국경선 공유 여부 확인
	while (Check_Union()) {
		// visited배열 초기화
		Visited_Init();
		// 국경선 공유
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Border_Opening(i, j);
			}
		}
		year++;
	}
	
	cout << year << "\n";
}

void Visited_Init(void) {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
	}
}

bool Check_Union(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i;
			int y = j;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				int sub = abs(graph[x][y] - graph[nx][ny]);
				if (sub >= l && sub <= r) {
					return true;
				}
			}
		}
	}
	return false;
}

// BFS
void Border_Opening(int a, int b) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;

	if (visited[a][b])
		return;

	q.push({ a,b });
	v.push_back({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			int sub = abs(graph[x][y] - graph[nx][ny]);
			if (sub >= l && sub <= r && !visited[nx][ny] ) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}
	// 연합을 이루는 각 칸의 인구수 구하기
	int union_population = Get_Union_Population(v);
	// 각 칸의 인구수를 설정
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		graph[x][y] = union_population;
	}
}

int Get_Union_Population(vector<pair<int,int>> v) {
	int population = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		population += graph[x][y];
	}

	return population / v.size();
}
