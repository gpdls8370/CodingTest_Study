#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> link(N);
	vector<int> cost(N);
	vector<int> answer(N , 0);
	vector<int> ind(N , 0);

	for(int i=0;i<N;i++){
		int a;
		cin >> cost[i] >> a;
		while (a != -1) {
			link[a - 1].push_back(i);
			ind[i]++;
			cin >> a;
		}
	}

	queue<int> que;
	for (int i = 0; i < N; i++) {
		if (ind[i] == 0) {
			que.push(i);
			answer[i] = cost[i];
		}
	}

	while (!que.empty()) {
		int a = que.front();
		que.pop();

		for (int i : link[a]) {
			if (--ind[i] == 0) {
				que.push(i);
			}
			answer[i] = max(answer[i] , answer[a] + cost[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << '\n';
	}
}