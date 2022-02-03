#include <iostream>
#include <queue>

using namespace std;

int n;
bool visited[1000001];

int bfs(int a) {
	queue<pair<int, int>>q;
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == 1) {
			return cnt;
		}
		if (!visited[num - 1]) {
			q.push(make_pair(num - 1, cnt + 1));
			visited[num - 1] = true;
		}
		
		if (num % 3 == 0 && num / 3 != 0 && !visited[num / 3]) {
			q.push(make_pair(num / 3, cnt + 1));
			visited[num / 3] = true;
		}
		if (num % 2 == 0 && num / 2 != 0 && !visited[num / 2]) {
			q.push(make_pair(num / 2, cnt + 1));
			visited[num / 2] = true;
		}
	}
}

int main() {
	cin >> n;
	cout << bfs(n);
	return 0;
}