#include <iostream>>
#include <queue>
using namespace std;

int maxN = -1000000001;
int minN = 1000000001;

void Calc(int now, queue<int> nextq, int plus, int minus, int mult, int divide) {
	if (nextq.empty()) {
		if (now > maxN) maxN = now;
		if (now < minN) minN = now;
		return;
	}
	int next = nextq.front();
	nextq.pop();

	if (plus > 0) {
		Calc(now + next, nextq, plus - 1, minus, mult, divide);
	}
	if (minus > 0) {
		Calc(now - next, nextq, plus, minus - 1, mult, divide);
	}
	if (mult > 0) {
		Calc(now * next, nextq, plus, minus, mult - 1, divide);
	}
	if (divide > 0) {
		Calc(now / next, nextq, plus, minus, mult, divide - 1);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	queue<int> nums;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		nums.push(a);
	}

	int plus, minus, mult, divide;
	cin >> plus >> minus >> mult >> divide;

	int first = nums.front();
	nums.pop();

	Calc(first, nums, plus, minus, mult, divide);

	cout << maxN << '\n' << minN;
}