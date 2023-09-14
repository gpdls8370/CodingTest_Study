#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<long> sum(N + 1, 0);
	vector<long> rm(M, 0);

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		sum[i] = (sum[i-1] + num) % M;
		rm[sum[i]]++;
	}

	long cnt = rm[0];

	for (int i = 0; i < M; i++) {
		if (rm[i] > 1) {
			cnt += rm[i] * (rm[i] - 1) / 2;
		}
	}
	cout << cnt;
}