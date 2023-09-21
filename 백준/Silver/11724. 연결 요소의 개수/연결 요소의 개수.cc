#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int GetNextStart(vector<bool> visited);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<bool> visited(N + 1, false);
	vector<vector<int>> linked(N + 1);
	stack<int> s;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		linked[a].push_back(b);
		linked[b].push_back(a);
	}

	while (true) {
		int next = GetNextStart(visited);
		
		if (next == 0) break;

		s.push(next);
		visited[next] = true;

		while (!s.empty()) {
			int num = s.top();
			s.pop();

			for (int i = 0; i < linked[num].size(); i++) {
				int linkNum = linked[num][i];
				if (!visited[linkNum]) {
					s.push(linkNum);
					visited[linkNum] = true;
				}	
			}
		}
		cnt++;
	}

	cout << cnt;
}

int GetNextStart(vector<bool> visited) {
	for (int i = 1; i < visited.size(); i++) {
		if (!visited[i]) return i;
	}
	return 0;
}