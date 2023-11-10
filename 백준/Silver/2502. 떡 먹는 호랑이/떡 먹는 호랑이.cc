#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int d , k;
	cin >> d >> k;

	int dpA[30];
	int dpB[30];

	dpA[0] = 1;
	dpA[1] = 0;
	dpB[0] = 0;
	dpB[1] = 1;

	for (int i = 2; i < d; i++) {
		dpA[i] = dpA[i - 2] + dpA[i - 1];
		dpB[i] = dpB[i - 2] + dpB[i - 1];
	}

	int a = dpA[d - 1];
	int b = dpB[d - 1];

	for (int i = 1; i < k; i++) {
		if ((k - a * i) % b == 0) {
			if ((k - a * i) / b >= i) {
				cout << i << '\n' << (k - a * i) / b;
				return 0;
			}
		}
	}
}