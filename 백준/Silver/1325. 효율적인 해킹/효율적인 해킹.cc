#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int s);
vector<vector<int>> link;
vector<bool> visit;
vector<int> cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N >> M;

	link.resize(N + 1);
	visit.resize(N + 1);
	cnt.resize(N + 1);

	for(int i=0;i<M;i++){
		int s , e;
		cin >> s >> e;
		link[s].push_back(e);
	}

	for (int i = 1; i <= N; i++) {
		if (!link[i].empty()) {
			fill(visit.begin() , visit.end() , false);
			BFS(i);
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < cnt[i]) max = cnt[i];
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == max) cout << i << ' ';
	}
}

void BFS(int s) {
	queue<int> que;
	que.push(s);
	visit[s] = true;

	while(!que.empty()){
		int node = que.front();
		que.pop();

		for (int next : link[node]) {
			if(!visit[next]){
				cnt[next]++;
				visit[next] = true;
				que.push(next);
			}
		}
	}
}
