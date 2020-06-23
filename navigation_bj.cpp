//https://www.acmicpc.net/problem/11403

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

vector<int> near[MAX];
queue<int> q;
int check[MAX][MAX];



void navigate(int N) {

	for (int s = 1; s <= N; s++) {

		q.push(s);
		
		while (!q.empty()) {

			int x = q.front();
			for (int i = 0; i < near[x].size(); i++) {
				if (check[s][near[x][i]] != 1) {
					q.push(near[x][i]);
					check[s][near[x][i]] = 1;
				}
			}
			q.pop();

		}
		
	}

}



int main() {

	int N;
	cin >> N;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			
			int connect;
			cin >> connect;
			if (connect) {
				near[x].push_back(y);
			}
				

		}
	}

	navigate(N);
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cout << check[x][y] << ' ';
		}
		cout << endl;
	}

}