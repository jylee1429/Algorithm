#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 1e9

using namespace std;

int t;

int main(void) {
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int min_val = INF;
		int max_val = -1;
		int sum = 0;
		int cnt = 0;
		int result = 0;
		double avg = 0;
		vector<int> v;

		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		for (int i = 0; i < 10; i++) {
			max_val = max(max_val, v[i]);
			min_val = min(min_val, v[i]);
		}

		for (int i = 0; i < 10; i++) {
			if (v[i] != max_val && v[i] != min_val) {
				sum += v[i];
				cnt++;
			}
		}

		avg = (double)sum / (double)cnt;
		result = (int)round(avg);
		cout << "#" << test_case + 1 << " " << result << "\n";
	}
}
