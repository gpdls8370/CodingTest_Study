#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	int mod = 1000000000;

	vector<vector<int>> D(N , vector<int>(10 , 1));
	D[0][0] = 0;

	for (int i = 1; i < N; i++) {
		D[i][0] = D[i - 1][1];
		for (int k = 1; k <= 8; k++) {
			D[i][k] = (D[i - 1][k - 1] + D[i - 1][k + 1]) % mod;
		}
		D[i][9] = D[i - 1][8];
	}

	long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + D[N - 1][i]) % mod;
	}

	cout << sum ;
}