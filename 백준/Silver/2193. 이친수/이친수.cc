#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<vector<long>> D(N , vector<long>(2));
	D[0][1] = 1;
	D[0][0] = 0;

	for (int i = 1; i < N; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	cout << D[N - 1][0] + D[N - 1][1];
}