#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N , M;
vector<vector<int>> map, temp;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int CountEmpty(){
	int cnt = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if (temp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void FillVirus(int x1, int y1, int x2, int y2, int x3, int y3){
	copy(map.begin() , map.end() , temp.begin());
	temp[x1][y1] = 1;
	temp[x2][y2] = 1;
	temp[x3][y3] = 1;

	queue<pair<int,int>> que;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if (temp[i][j] == 2) {
				que.push(make_pair(i , j));
			}
		}
	}

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int k = 0; k < 4; k++) {
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
				if (temp[newX][newY] == 0) {
					temp[newX][newY] = 2;
					que.push(make_pair(newX , newY));
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	map.resize(N, vector<int>(M));
	temp.resize(N , vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;

	for (int i1 = 0; i1 < N; i1++) {
		for (int j1 = 0; j1 < M; j1++) {
			if (map[i1][j1] == 0) {

				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < M; j2++) {
						if (map[i2][j2] == 0 && !(i1==i2 &&j1==j2)){

							for (int i3 = 0; i3 < N; i3++) {
								for (int j3 = 0; j3 < M; j3++) {
									if (map[i3][j3] == 0 && !(i1 == i3 && j1 == j3) && !(i2 == i3 && j2 == j3)) {
										FillVirus(i1 , j1 , i2 , j2 , i3 , j3);
										result = max(result , CountEmpty());
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << result;
}