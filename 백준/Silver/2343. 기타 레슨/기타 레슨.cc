#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N >> M;

	vector<int> arr;
	arr.resize(N);

	int start = 0;
	int end = 0;

	for(int i=0;i<N;i++){
		int num;
		cin >> num; 
		arr[i] = num;
		if (num > start) start = num;
		end += num;
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		int count = 1;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			sum += arr[i];
			if (sum > mid) {
				sum = 0;
				count++;
				i--;
			}
		}

		if (count <= M) end = mid - 1;
		else start = mid + 1;
	}

	cout << start;
}