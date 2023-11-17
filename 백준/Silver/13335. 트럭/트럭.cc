#include <iostream>
#include <queue>
using namespace std;

int n , w , L;
int dist[1000] = { 0, };
queue<int> wait;
queue<int> bridge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		wait.push(weight);
	}

	int nowWeight = 0;
	int front = 0;
	int end = -1;
	int result = 0;

	while (front < n) {
		result++;

		//다리에 있는 트럭 한칸씩 이동
		for (int i = front; i <= end; i++) {
			dist[i]++;
		}
		
		//다리 탈출
		if (front <= end && dist[front] > w) {
			nowWeight -= bridge.front();
			bridge.pop();
			front++;
		}

		if (!wait.empty()) {
			int newWeight = wait.front();
			if (L - nowWeight >= newWeight) {
				nowWeight += newWeight;
				bridge.push(newWeight);
				wait.pop();
				dist[++end] = 1;
			}
		}
	}
	cout << result;
}