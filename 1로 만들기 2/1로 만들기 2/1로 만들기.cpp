#include <iostream>
#include <queue>
#include <vector>
#define MAX (10001 + 1)
#define INF 987654321

using namespace std;

vector<pair<int, int>> vertex[MAX];
int dis[MAX];
int dist[MAX];
int N, D;

void init() {
	for (int i = 1; i <= D; i++) {
		dis[i] = i;
	}
	for (int i = 1; i <= D; i++) {
		dist[i] = INF;
	}
}

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < vertex[cur].size(); i++) {
			int nCur = vertex[cur][i].first;
			int nCost = vertex[cur][i].second + cost;
			//cout << dis[nCur] << " ";
			//cout << nCost << "\n";
			//cout << dist[nCur] << " ";
			if (dist[nCur] > nCost /*&& dis[nCur] > dist[nCur]*/) {
				dist[nCur] = nCost;
				pq.push(make_pair(dist[nCur], nCur));
			}
			else {
				dist[nCur] = dis[nCur];
				pq.push(make_pair(dist[nCur], nCur));
			}
		}
	}
}

int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
	}
	init();
	dijkstra();
	/*for (int i = 0; i <= D; i++)
		cout << dist[i];*/
	return 0;
}