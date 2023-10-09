#include <iostream>
#include <vector>
using namespace std;

void Union(int a , int b);
int Find(int a);

vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N >> M;

	arr.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	int link;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> link;

			if (j < i && link == 1) {
				Union(i , j);
			}
		}
	}

	int first, a, b;
	cin >> first;
	a = Find(first);
	for (int i = 0; i < M - 1; i++) {
		cin >> b;
		if (a != Find(b)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}

void Union(int a, int b){
	arr[Find(b)] = Find(a);
}

int Find(int a){
	if (arr[a] != a)
		arr[a] = Find(arr[a]);

	return arr[a];
}