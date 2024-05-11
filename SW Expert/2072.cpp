#include <iostream>
#include <vector>

using namespace std;

int Add_Odd(vector<int> temp);

int main(void) {
	int t;
	cin >> t;

	for (int test_case = 0; test_case < t; test_case++) {
		vector<int> v;

		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		int result = Add_Odd(v);
		cout << "#" << test_case + 1 << " " << result << endl;
	}
}

int Add_Odd(vector<int> temp) {
	int sum = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] % 2) {
			sum += temp[i];
		}
	}

	return sum;
}
