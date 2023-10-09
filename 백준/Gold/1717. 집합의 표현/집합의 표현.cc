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

	int n , m;
	cin >> n >> m;

	arr.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int order;
		int a , b;
		cin >> order >> a >> b;

		if (order == 0) {
			Union(a , b);
		}
		else {
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

void Union(int a, int b){
	arr[Find(b)] = Find(a);
}

int Find(int a){
	if (a != arr[a])
		arr[a] = Find(arr[a]);

	return arr[a];
}