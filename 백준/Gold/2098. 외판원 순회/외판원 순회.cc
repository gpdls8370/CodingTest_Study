#include <iostream>
using namespace std;

int N;
int inf = 1000000 * 16 + 1;
int W[16][16];
int D[16][(1 << 16)];

int dp(int c , int v);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	cout << dp(0 , 1);

}

int dp(int c, int v){
	if (v == (1 << N) - 1) {
		if(W[c][0] == 0){
			return inf;
		}
		return W[c][0];
	}
	
	if (D[c][v] != 0) {
		return D[c][v];
	}

	int result = inf;
	for (int i = 0; i < N; i++) {
		if ((v & (1 << i)) == 0 && W[c][i] != 0) {
			//방문하지 않음
			result = min(result , dp(i , (v | (1 << i))) + W[c][i]);
		}
	}

	return D[c][v] = result;
}