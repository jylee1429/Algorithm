#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define SIZE 50
#define INF 1e9

using namespace std;

int t;
int n, k;
int graph[SIZE][SIZE];
int graph_distance[SIZE][SIZE];

int Select_Tile(int x, int y);
int Get_Distance(int a, int b, int c, int d);

int main(void) {
	cin >> t;
	for (int test_code = 0; test_code < t; test_code++) {
		int result = INF;

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
				graph_distance[i][j] = INF;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == 1) {
					result = min(result, Select_Tile(i, j));
				}
			}
		}
		if (result == INF)
			result = -1;

		cout << "#" << test_code + 1 << " " << result << endl;
	}
}

int Select_Tile(int x, int y) {
	if (graph[x][y] == k)
		return 0;
	if (graph_distance[x][y] != INF) {
		return graph_distance[x][y];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == graph[x][y] + 1) {
				int distance = Get_Distance(x, y, i, j);
				graph_distance[x][y] = min(graph_distance[x][y], Select_Tile(i, j) + distance);
			}
		}
	}

	return graph_distance[x][y];
}

int Get_Distance(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}
