#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
const int inf = 300001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<edge>> link(V + 1);
	vector<bool> visited(V + 1, false);
	vector<int>	dist(V + 1, inf);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		link[u].push_back(make_pair(v, w));
	}

	dist[K] = 0;
	priority_queue<edge, vector<edge>, greater<edge>> que;
	que.push(make_pair(0, K));

	while (!que.empty()) {
		edge e = que.top();
		que.pop();

		if (visited[e.second]) continue;
		visited[e.second] = true;

		for (edge n : link[e.second]) {
			int next = n.first;
			int value = n.second;

			if (!visited[next]) {
				if (dist[next] > e.first + value) {
					dist[next] = min(dist[next], e.first + value);
					que.push(make_pair(dist[next], next));
				}		
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == inf) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}