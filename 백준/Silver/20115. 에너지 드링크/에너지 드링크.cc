#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int max = 0;
	long sum = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num > max) {
			sum += max;
			max = num;
		}
		else {
			sum += num;
		}
	}

	cout << max + sum / 2.0f;
}
