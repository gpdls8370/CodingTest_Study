#include <iostream>
#include <queue>
using namespace std;

void BFS();
int link[101];
int minCnt[101];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N >> M;

	fill_n(link , 101 , -1);
	fill_n(minCnt , 101 , 100);

	int a , b;
	for (int i = 0; i < N + M; i++) {
		cin >> a >> b;
		link[a] = b;
	}

	BFS();

	cout << minCnt[100];
}

void BFS(){
	queue<pair<int , int>> que;
	que.push(make_pair(1 , 0));

	int now , cnt , next;
	while (!que.empty()) {
		now = que.front().first;
		cnt = que.front().second;
		que.pop();

		if (link[now] != -1) {
			now = link[now];
			if (cnt < minCnt[now]) {
				minCnt[now] = cnt;
			}
			else{
				continue;
			}
		}

		for (int i = 1; i <= 6; i++) {
			next = now + i;
			if (next <= 100 && cnt + 1 < minCnt[next]) {
				que.push(make_pair(next , cnt + 1));
				minCnt[next] = cnt + 1;
			}
		}
	}

}