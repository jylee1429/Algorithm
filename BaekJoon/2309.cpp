#include <bits/stdc++.h>
#define NUM 9
#define TARGET 100

using namespace std;

vector<int> v;
vector<int> result;
vector<bool> temp{ 1,1,1,1,1,1,1,0,0 };

int main(void) {
	for (int i = 0; i < NUM; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < NUM; i++) {
			if (temp[i]) {
				sum += v[i];
			}
		}
		if (sum == TARGET) {
			for (int i = 0; i < NUM; i++) {
				if (temp[i]) {
					result.push_back(v[i]);
				}
			}
			break;
		}
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}
