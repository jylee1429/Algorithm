#include <bits/stdc++.h>
#define SIZE 100001

using namespace std;

int t;
int cnt = 0;
int student[SIZE];
bool visited[SIZE];
bool cycle_check[SIZE];

void DFS(int current_student);
void Init(void);

int main(void) {
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			student[j] = x;
		}

		Init();

		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				DFS(j);
			}
		}

		cout << n - cnt << "\n";
	}

}


void DFS(int current_student) {
	visited[current_student] = true;

	int favority_student = student[current_student];

	if (!visited[favority_student]) {
		DFS(favority_student);
	}
	else if (!cycle_check[favority_student]) {
		for (int i = favority_student; i != current_student; i = student[i]) {
			cnt++;
		}
		cnt++;
	}

	cycle_check[current_student] = true;
}

void Init(void) {
	cnt = 0;
	fill_n(visited, SIZE, false);
	fill_n(cycle_check, SIZE, false);
}
