#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int val = i;
		bool flag = false;
		vector<int> v;

		while (val > 0) {
			v.push_back(val % 10);
			val /= 10;
		}

		for (int j = 0; j < v.size(); j++) {
			if (v[j] == 3 || v[j] == 6 || v[j] == 9) {
				cout << "-";
				flag = true;
			}
		}

		if (!flag) {
			cout << i;
		}
		cout << " ";
	}
}
