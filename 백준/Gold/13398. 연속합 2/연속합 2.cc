#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> dpL(N);
	vector<int> dpR(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = arr[0];

	dpL[0] = arr[0];
	for (int i = 1; i <= N - 1; i++) {
		dpL[i] = max(dpL[i - 1] + arr[i] , arr[i]);
		result = max(result , dpL[i]);
	}

	dpR[N - 1] = arr[N - 1];
	result = max(result , dpR[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		dpR[i] = max(dpR[i + 1] + arr[i] , arr[i]);
		result = max(result , dpR[i]);
	}

	for (int i = 1; i < N - 1; i++) {
		result = max(result , dpL[i - 1] + dpR[i + 1]);
	}

	cout << result;
}