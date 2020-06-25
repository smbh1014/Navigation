// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <queue>

#define MAX 25

using namespace std;


typedef struct POINT {
	int x, y;
}point;

int map[MAX][MAX];
int number[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int num = 1;
queue<point> q;
int blocks[MAX * MAX];

void queuePrint() {

	queue<point> temp;
	
	while (!q.empty()) {
		temp.push(q.front());
		q.pop();
	}
	while (!temp.empty()) {
		q.push(temp.front());
		cout << temp.front().x << ", " << temp.front().y << ' ';
		temp.pop();
	}
	cout << endl;
	


}

void numbering(int N) {

	int x, y;
	int nx, ny;
	int flag = false;

	for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++) {

			point p, np;
			p.x = x; p.y = y;
			if ((map[p.x][p.y] == 1) && (number[p.x][p.y] == 0)) {
				q.push(p);
			}
				

			while (!q.empty()) {
				flag = true;
				p = q.front();
				q.pop();
				number[p.x][p.y] = num;
				for (int i = 0; i < 4; i++) {
					nx = p.x + dx[i]; ny = p.y + dy[i];
					np.x = nx; np.y = ny;
					if ((map[np.x][np.y] == 1) && (number[np.x][np.y] == 0))
						q.push(np);
				}
			}

			if (flag) {
				num++;
				flag = false;
			}
				
						

		}
	}

}

int main() {

	int N, series;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> series;
		for (int k = N - 1; k >= 0; k--) {
			map[i][k] = series % 10;
			series = series / 10;
		}
	}
	numbering(N);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			blocks[number[x][y]]++;

		}
	}
	
	cout << num - 1 << endl;
	for (int i = 1; i < num; i++)
		cout << blocks[i] << endl;

}