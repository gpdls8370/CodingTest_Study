#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N , K;
int minD[100001];
int maxP;
void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	fill_n(minD , 100001 , 100001);
	maxP = K * 2;
	maxP = min(maxP , 100000);
	
	BFS();
	cout << minD[K];
}

void BFS(){
	queue<pair<int,int>> que;

	que.push(make_pair(N , 0));
	minD[N] = 0;
	while (!que.empty()) {
		int num = que.front().first;
		int dist = que.front().second;
		que.pop();

		if (num + 1 <= maxP && minD[num+1] > dist + 1) {
			minD[num + 1] = dist+1;
			que.push(make_pair(num + 1 , dist + 1));
		}
		if (num - 1 >= 0 && minD[num - 1] > dist + 1) {
			minD[num - 1] = dist + 1;
			que.push(make_pair(num - 1 , dist + 1));
		}
		if (num * 2 <= maxP && minD[num * 2] > dist) {
			minD[num * 2] = dist;
			que.push(make_pair(num * 2 , dist));
		}
	}
}