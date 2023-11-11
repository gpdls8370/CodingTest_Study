#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;
	priority_queue<long, vector<long>, greater<long>> cards;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards.push(num);
	}

	long a , b;
	for (int i = 0; i < m; i++) {
		a = cards.top();
		cards.pop();
		b = cards.top();
		cards.pop();

		cards.push(a + b);
		cards.push(a + b);
	}

	long sum = 0;
	while (!cards.empty()) {
		sum += cards.top();
		cards.pop();
	}

	cout << sum;
}