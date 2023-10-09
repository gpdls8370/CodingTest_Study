#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int s);
vector<vector<int>> link;
vector<int> dist;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M , K , X;
	cin >> N >> M >> K >> X;

	link.resize(N + 1);
	dist = vector<int>(N + 1 , -1);

	for(int i=0;i<M;i++){
		int s , e;
		cin >> s >> e;
		link[s].push_back(e);
	}

	BFS(X);

	bool exist = false;

	for(int i=1;i<=N;i++){
		if (dist[i] == K) {
			cout << i << '\n';
			exist = true;
		}
	}
	if (!exist) cout << -1;
}

void BFS(int s) {
	queue<int> que;
	que.push(s);
	dist[s] = 0;

	while (!que.empty()){
		int node = que.front();
		que.pop();

		for (int a : link[node]) {
			if (dist[a] == -1) {
				que.push(a);
				dist[a] = dist[node] + 1;
			}
		}
	}
}
