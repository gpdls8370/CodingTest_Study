#include <iostream>
#include <vector>
using namespace std;

int inf = 10000001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	vector<vector<long>> map(n + 1 , vector<long>(n + 1 , inf));

	for (int i = 1; i <= n; i++) {
		map[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a , b , c;
		cin >> a >> b >> c;
		if (map[a][b] > c) {
			map[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				map[s][e] = min(map[s][e] , map[s][k] + map[k][e]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == inf) cout << "0 ";
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}