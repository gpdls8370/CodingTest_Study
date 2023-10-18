#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a , z , k;
	cin >> a >> z >> k;

	vector<vector<long>> cost(a + z + 1 , vector<long>(a + z + 1));

	for (int i = 0; i <= a + z; i++) {
		cost[i][0] = 1;
		cost[i][i] = 1;
	}
	for (int i = 1; i <= a + z; i++) {
		for (int j = 1; j <= i; j++) {
			cost[i][j] = cost[i - 1][j] + cost[i - 1][j - 1];
			if (cost[i][j] > 1000000000) {
				cost[i][j] = 1000000001;
			}
		}
	}

	if (cost[a + z][a] < k) {
		cout << -1;
		return 0;
	}

	while (a != 0 || z != 0) {
		if (cost[a + z - 1][z] >= k) {
			//a선택
			cout << 'a';
			a--;
		}
		else {
			//z선택
			k -= cost[a + z - 1][z];
			cout << 'z';
			z--;
		}
	}

	while (a > 0) {
		cout << 'a';
		a--;
	}
	while (z > 0) {
		cout << 'z';
		z--;
	}
}