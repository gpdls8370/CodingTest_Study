#include <iostream>
#include <deque>
#include <utility>
using namespace std;

struct node {
	int index;
	int value;
};

deque<node> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		node a;
		a.index = i;
		cin >> a.value;
		
		while (que.size() > 0 && a.value <= que.back().value) {
			que.pop_back();
		}
		que.push_back(a);

		while (que.front().index <= i - L) {
			que.pop_front();
		}

		cout << que.front().value << ' ';
	}
}
