#include <iostream>
using namespace std;

bool visited[50][50];
int map[50][50];
int M , N;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void DFS(int x, int y){
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || a>=M || b<0 || b>=N) continue;

		if (map[a][b] == 1 && !visited[a][b]) {
			DFS(a , b);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, K;
	cin >> T;

	while (T > 0) {
		T--;
		cin >> M >> N >> K;

		fill_n(&map[0][0] , 2500 , 0);
		fill_n(&visited[0][0] , 2500 , false);

		for (int i = 0; i < K; i++) {
			int a , b;
			cin >> a >> b;
			map[a][b] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					DFS(i , j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}