#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> dpU(N , 1) , dpD(N , 1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[k] < arr[i]) {
				dpU[i] = max(dpU[i] , dpU[k] + 1);
			}
		}
	}

	for (int i = N-2; i >= 0; i--) {
		for (int k = N-1; k > i; k--) {
			if (arr[k] < arr[i]) {
				dpD[i] = max(dpD[i] , dpD[k] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		result = max(result, dpU[i] + dpD[i]);
	}
	
	cout << result - 1;
}