#include <iostream>
#include <vector>
#include <queue>
#define MAX (50 + 1)

using namespace std;

vector<pair<int, int>> vertex[MAX];
char map[MAX][MAX];
int dist[MAX];
int n, m;

void dijkstra() {
	
}

void findG(int y, int x) {
	map[y][x + 1] = 1;
	map[y][x - 1] = 1;
	map[y - 1][x] = 1;
	map[y + 1][x] = 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'g') {
				findG(i, j);
				map[i][j] = 5000;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
	}
}