#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int num;
	int p;
	int q;
};

vector<long> result;
vector<vector<Node>> link;
long totGcd;

void Calc(int a, Node n);

long gcd(long a, long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	link.resize(N);
	result = vector<long>(N, 0);
	long x = 1;

	for (int i = 0; i < N-1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;

		Node n;
		n.num = b;
		n.p = p;
		n.q = q;

		link[a].push_back(n);

		n.num = a;
		n.p = q;
		n.q = p;
		link[b].push_back(n);

		x *= p * q / gcd(p, q);
	}
	result[0] = x;
	totGcd = x;

	for (Node next : link[0])
		Calc(0, next);

	for (long a : result)
		cout << a / totGcd << ' ';
}

void Calc(int a, Node n) {
	result[n.num] = result[a] * n.q / n.p;
	totGcd = gcd(totGcd, result[n.num]);

	for (Node next : link[n.num]) {
		if (result[next.num] == 0) {
			Calc(n.num, next);
		}
	}
}