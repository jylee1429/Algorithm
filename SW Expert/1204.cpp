#include <iostream>
#include <algorithm>
#define SIZE 1001

using namespace std;

int t;
int test_num;

int main(void) {
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int score[SIZE] = { 0 };

		cin >> test_num;

		for (int i = 1; i < SIZE; i++) {
			int n;
			cin >> n;
			score[n]++;
		}

		int max_val = -1;
		int index = 0;

		for (int i = 1; i < SIZE; i++) {
			if (max_val <= score[i]) {
				max_val = score[i];
				index = i;
			}
		}
		cout << "#" << test_num << " " << index << endl;
	}
}
