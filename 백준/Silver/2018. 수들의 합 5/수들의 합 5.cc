#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	int sum = 0; 
	int start = 1;
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		sum += i;

		if (sum > N) {
			while (sum > N) {
				sum -= start;
				start++;
			}
		}

		if (sum == N) {
			cnt++;
		}
	}

	cout << cnt;
}