#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int , int , int> edge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<edge> edges;
	//언더플로우 때문에 long으로
	vector<long> dist(N + 1 , LONG_MAX);

	for (int i = 0; i < M; i++) {
		int a , b , c;
		cin >> a >> b >> c;
		edges.push_back(make_tuple(a , b , c));
	}

	dist[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (edge e : edges) {
			int start = get<0>(e);
			int end = get<1>(e);
			int value = get<2>(e);

			if (dist[start] == LONG_MAX) continue;

			long nextDist = dist[start] + value;
			if (nextDist < dist[end]) {
				dist[end] = nextDist;
			}
		}
	}

	bool cycle = false;
	for (edge e : edges) {
		int start = get<0>(e);
		int end = get<1>(e);
		int value = get<2>(e);

		if (dist[start] == LONG_MAX) continue;

		long nextDist = dist[start] + value;
		if (nextDist < dist[end]) {
			cycle = true;
			break;
		}
	}

	if (cycle) cout << "-1";
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == LONG_MAX) cout << "-1";
			else cout << dist[i];
			cout << '\n';
		}
	}
}