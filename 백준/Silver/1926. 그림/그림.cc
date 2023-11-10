#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	vector<vector<int>> map(n + 2 , vector<int>(m + 2 , 0));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	vector<vector<bool>> visited(n+2 , vector<bool>(m+2 , false));
	queue<pair<int, int>> que;
	int maxSize = 1;
	int count = 0;

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			if (!visited[a][b] && map[a][b] == 1) {
				count++;
				int size = 1;
				visited[a][b] = true;

				que.push(make_pair(a , b));
				while (!que.empty()) {
					int i = que.front().first;
					int j = que.front().second;
					que.pop();

					if (!visited[i + 1][j] && map[i + 1][j] == 1) {
						que.push(make_pair(i + 1 , j));
						visited[i +1][j] = true;
						size++;
					}
					if (!visited[i][j + 1] && map[i][j + 1] == 1) {
						que.push(make_pair(i , j + 1));
						visited[i][j+1] = true;
						size++;
					}
					if (!visited[i - 1][j] && map[i - 1][j] == 1) {
						que.push(make_pair(i - 1 , j));
						visited[i - 1][j] = true;
						size++;
					}
					if (!visited[i][j - 1] && map[i][j - 1] == 1) {
						que.push(make_pair(i , j - 1));
						visited[i][j - 1] = true;
						size++;
					}
				}
				maxSize = max(maxSize , size);
			}
		}
	}
	
	cout << count << '\n';

	if (count == 0) cout << 0;
	else cout << maxSize;
}