#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<pair<int,int>> rank(N);
		for(int j=0;j<N;j++){
			int a , b;
			cin >> a >> b;
			rank[j] = make_pair(a , b);
		}

		sort(rank.begin() , rank.end());
		int topRank = rank[0].second;
		int count = 1;
		for (int k = 1; k < N; k++) {
			if (topRank > rank[k].second) {
				count++;
				topRank = rank[k].second;
			}
		}
		cout << count << '\n';
	}
}