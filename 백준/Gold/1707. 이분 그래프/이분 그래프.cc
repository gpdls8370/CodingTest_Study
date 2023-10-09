#include <iostream>
#include <vector>
using namespace std;

void DFS(int n);
vector<vector<int>> link;
vector<int> visited;
bool result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;

	for(int i=0;i<K;i++){
		int V , E;
		cin >> V >> E;

		link = vector<vector<int>>(V + 1);
		visited = vector<int>(V + 1 , -1);

		for (int j = 0; j < E; j++) {
			int s , e;
			cin >> s >> e;
			link[s].push_back(e);
			link[e].push_back(s);
		}

		result = true;

		for (int n = 1; n <= V; n++) {
			if (visited[n] == -1) {
				DFS(n);
			}
		}

		if (result) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

void DFS(int n){
	if (!result) return;

	for(int i : link[n]){
		if(visited[i] == -1){
			visited[i] = (visited[n] + 1) % 2;
			DFS(i);
		}
		else if(visited[i] == visited[n]){
			result = false;
			return;
		}
	}
}