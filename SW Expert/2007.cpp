#include <iostream>
#include <vector>

#define SIZE 30
using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<char> v;
		string s;
		
		cin >> s;

		v.push_back(s[0]);
		
		for (int j = 1; j < SIZE; j++) {
			// 문자열 처음 문자와 다른 문자인 경우
			if (s[j] != v[0]) {
				v.push_back(s[j]);
			}
			// 문자열 처음 문자와 같은 문자인 경우
			else {
				// v.size()만큼 비교
				int cnt = 0;
				for (int k = j; k < j + v.size(); k++) {
					if (s[k] == v[k - j])
						cnt++;
					else {
						v.push_back(s[j]);
						break;
					}
				}
				if (cnt == v.size())
					break;
			}
		}
		cout << "#" << i + 1 << " " << v.size() << endl;
	}
}
