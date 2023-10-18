#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	vector<vector<int>> dp(n , vector<int>(m));
	int result = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			dp[i][j] = str[j] - '0';

			if (i > 0 && j > 0 && dp[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j] , min(dp[i - 1][j - 1] , dp[i][j - 1])) + 1;
			}
			result = max(result , dp[i][j]);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {

		}
	}

	cout << result * result;
}