#include <bits/stdc++.h>

#define SIZE 21
#define INF 1e9

using namespace std;

int n;
int result = INF;
int stats[SIZE][SIZE];


int main(void) {
	cin >> n;
	vector<bool> temp(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	fill_n(temp.begin(), n / 2, true);
	sort(temp.begin(), temp.end());

	do {
		vector<int> start;
		vector<int> link;
		int  start_stats = 0;
		int link_stats = 0;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i]) {
				start.push_back(i + 1);
			}
			else {
				link.push_back(i + 1);
			}
		}

		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				if (i != j) {
					start_stats += stats[start[i]][start[j]];
				}
			}
		}

		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				if (i != j) {
					link_stats += stats[link[i]][link[j]];
				}
			}
		}

		int val = abs(start_stats - link_stats);

		if (result > val) {
			result = val;
		}
	} while (next_permutation(temp.begin(), temp.end()));

	cout << result;
}
