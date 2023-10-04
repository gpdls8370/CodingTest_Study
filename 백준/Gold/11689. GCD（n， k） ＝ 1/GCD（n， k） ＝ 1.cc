#include <iostream>>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long n;
	cin >> n;
	long result = n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			result = result - result / i;
			
			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if(n  > 1)
		result = result - result / n;

	cout << result;
}