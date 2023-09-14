#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> sums(N + 1, vector<int>(N + 1, 0));

	for (int x = 1; x <= N ; x++) {
		for (int y = 1; y <= N; y++) {
			int num;
			cin >> num;

			sums[x][y] = sums[x - 1][y] + sums[x][y - 1] - sums[x - 1][y - 1] + num;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1] << "\n";
	}

}