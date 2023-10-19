#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int DP(int i, int j);
vector<vector<int>> dp;
vector<int> L;
vector<int> R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	L.resize(N);
	R.resize(N);
	dp.resize(N , vector<int>(N, -1));

	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
		dp[i][i] = 0;

		if (i > 0) {
			dp[i - 1][i] = L[i - 1] * R[i - 1] * R[i];
		}
	}

	cout << DP(0 , N - 1);

}

int DP(int i, int j){
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int result = INT_MAX;
	for (int k = i; k < j; k++) {
		result = min(result , DP(i , k) + DP(k + 1 , j) + L[i] * R[k] * R[j]);
	}
	return dp[i][j] = result;
}