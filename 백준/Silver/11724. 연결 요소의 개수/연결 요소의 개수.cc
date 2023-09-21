#include <iostream>
#include <vector>
using namespace std;

void DFS(int num);
vector<bool> visited;
vector<vector<int>> linked;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	visited = vector<bool>(N + 1, false);
	linked.resize(N + 1);
	
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		linked[a].push_back(b);
		linked[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { 
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;
}

void DFS(int num) {
	if (visited[num]) return;

	visited[num] = true;

	for (int next : linked[num]) {
		if (!visited[next]) DFS(next);
	}
}