#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> link;
vector<priority_queue<int, vector<int>>> dist;
int k;

void Dijkstra(int start);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m >> k;

	 link.resize(n + 1);
	 dist.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		
		link[s].push_back(make_pair(e, t));
	}

	dist[1].push(0);
	Dijkstra(1);

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << "-1\n";
		else cout << dist[i].top() << '\n';
	}
}

void Dijkstra(int start) {
	priority_queue<edge, vector<edge>, greater<edge>> que;
	que.push(make_pair(0, start));

	while (!que.empty()) {
		edge e = que.top();
		que.pop();
		int now = e.second;
		int nowDist = e.first;

		for (int i = 0; i < link[now].size(); i++) {
			int next = link[now][i].first;
			int value = link[now][i].second;

			int nextDist = nowDist + value;
			if (dist[next].size() < k) {
				dist[next].push(nextDist);
				que.push(make_pair(nextDist, next));
			}
			else if (dist[next].top() > nextDist) {
				dist[next].pop();
				dist[next].push(nextDist);
				que.push(make_pair(nextDist, next));
			}
		}
	}
}