#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long A, B;
	cin >> A >> B;

	if (A > B) swap(A, B);

	long long r;

	while (true) {
		r = B % A;
		if (r == 0) break;
		B = A;
		A = r;
	}

	for (int i = 0; i < A; i++) {
		cout << 1;
	}
}