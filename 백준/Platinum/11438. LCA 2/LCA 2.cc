#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> link;
vector<vector<int>> parent;
vector<int> depth;
vector<bool> visit;
int kmax = 0;
void DFS(int num , int d);
int Find(int a , int b);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	link.resize(N + 1);
	depth.resize(N + 1);
	visit.resize(N + 1 , false);
	parent.resize(21 , vector<int>(N + 1 , 0));

	for (int i = 1; i < N; i++) {
		int a , b;
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	int temp = 1;
	while (temp <= N) {
		temp <<= 1;
		kmax++;
	}

	DFS(1, 0);

	//dp
	for (int k = 1; k <= kmax; k++) {
		for (int i = 1; i <= N; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a , b;
		cin >> a >> b;
		cout << Find(a , b) << '\n';
	}

}

void DFS(int num, int d){
	depth[num] = d;
	visit[num] = true;

	for (int next : link[num]) {
		if (!visit[next]) {
			parent[0][next] = num;
			DFS(next , d + 1);
		}
	}
}

int Find(int a , int b) {
	if (a == b) return a;
	if (depth[a] > depth[b]) swap(a , b);

	for (int k = kmax; k >= 0; k--) {
		if (pow(2 , k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}

	for (int k = kmax; k >= 0; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	if (a != b) {
		a = parent[0][a];
	}

	return a;
}