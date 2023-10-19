#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> D;
vector<int> B;
int maxIdx = 0;

int search(int s, int e, int num){
	while(s < e){
		int m = (s + e) / 2;
		if (B[m] < num) {
			s = m + 1;
		}
		else{
			e = m;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	arr.resize(N);
	D.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	B.resize(N);
	D[0] = 1;
	int length = 1;
	B[0] = arr[0];

	for (int i = 1; i < N; i++) {
		if (B[length-1] < arr[i]) {
			B[length++] = arr[i];
			D[i] = length;
		}
		else {
			int idx = search(0 , length - 1 , arr[i]);
			B[idx] = arr[i];
			D[i] = idx+1;
		}
	}

	cout << length << '\n';

	vector<int> result(length);
	int temp = B[length - 1] + 1;

	for (int i = N-1; i >= 0; i--) {
		if (D[i] == length && temp > arr[i]) {
			length--;
			result[length] = arr[i];
			temp = arr[i];
		}
	}
	for (int a : result) {
		cout << a << ' ';
	}
}
