#include <bits/stdc++.h>
#define SIZE 50
#define INF 1e9

using namespace std;

int n, m;
int city[SIZE][SIZE];
vector<pair<int, int>> store;
vector<pair<int, int>> house;

void Combination(void);
int Get_Distance(vector<pair<int, int>> v);

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			city[i][j] = x;
			if (x == 2) {
				store.push_back({ i,j });
			}
			else if (x == 1) {
				house.push_back({ i,j });
			}
		}
	}

	Combination();
}

void Combination(void) {
	vector<bool> temp(store.size());
	int min_distance = INF;

	// temp중 m개를 true로 설정
	fill(temp.end() - m, temp.end(), true);
	do {
		vector<pair<int, int>> renewal_store;
		for (int i = 0; i < store.size(); i++) {
			if (temp[i]) {
				int x = store[i].first;
				int y = store[i].second;

				renewal_store.push_back({ x,y });
			}
		}
		// 최소 거리 구하기
		min_distance = min(min_distance, Get_Distance(renewal_store));
	} while (next_permutation(temp.begin(), temp.end()));

	cout << min_distance;
}

int Get_Distance(vector<pair<int,int>> store) {
	int total_distance = 0;

	for (int i = 0; i < house.size(); i++) {
		int house_x = house[i].first;
		int house_y = house[i].second;
		int distance = INF;
		// 현재 집과 가까운 거리의 가게 찾기
		for (int j = 0; j < store.size(); j++) {
			int store_x = store[j].first;
			int store_y = store[j].second;

			int d = abs(house_x - store_x) + abs(house_y - store_y);
			distance = min(distance, d);
		}
		// 각 집마다 가까운 가게와의 거리 총 합
		total_distance += distance;
	}

	return total_distance;
}
