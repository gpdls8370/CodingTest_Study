#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		int k = 1;
		
		if (a > b) swap(a, b);

		for (int k = 1; k <= b; k++) {
			if (a * k % b == 0) { 
				cout << a * k << '\n';
				break;
			}
		}
	}

}