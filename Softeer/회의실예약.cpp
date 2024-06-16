#include <bits/stdc++.h>

#define SIZE 51

using namespace std;

int n, m;
string arr[SIZE];
vector<pair<int, int>> room[SIZE];
vector<pair<int, int>> possible_time[SIZE];

void Int_To_String(int x, int y);

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		string str;
		int x, y;
		cin >> str >> x >> y;
		for (int j = 0; j < n; j++) {
			if (str == arr[j]) {
				room[j].push_back({ x,y });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		sort(room[i].begin(), room[i].end());
	}
	// sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < n; i++) {
		int start = 9;
		int end = 18;
		for (int j = 0; j < room[i].size(); j++) {
			if (room[i][j].first - start > 0) {
				possible_time[i].push_back({ start,room[i][j].first });
			}
			start = room[i][j].second;
		}
		if (end - start > 0) {
			possible_time[i].push_back({ start,end });
		}

		cout << "Room " << arr[i] << ":" << "\n";
		if (possible_time[i].size() == 0) {
			cout << "Not available" << "\n";
		}
		else {
			cout << possible_time[i].size() << " available:" << "\n";
			for (int j = 0; j < possible_time[i].size(); j++) {
				// cout << possible_time[i][j].first << "-" << possible_time[i][j].second << "\n";
				Int_To_String(possible_time[i][j].first, possible_time[i][j].second);
			}
		}
		if (i != n - 1) {
			cout << "-----" << '\n';
		}
	}
}

void Int_To_String(int x, int y) {
	if (x < 10) {
		cout << "0" << x << "-";
	}
	else {
		cout << x << "-";
	}
	if (y < 10) {
		cout << "0" << y << "\n";
	}
	else {
		cout << y << "\n";
	}

}
