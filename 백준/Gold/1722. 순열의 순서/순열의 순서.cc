#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> used;
//남은 수 중에서 idx번째 수 리턴
int GetNum(int idx) {
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			if (--idx == 0) {
				used[i] = true;
				return i;
			}
		}
	}
}

//남은 수 중에서 몇번째 수 인지
int GetIdx(int num) {
	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		if (!used[i]) {
			cnt++;
		}
	}

	used[num] = true;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> N >> num;

	vector<long> arr(N+1);
	used.resize(N + 1, false);

	arr[0] = 1;
	for (int i = 1; i <= N; i++) {
		arr[i] = arr[i - 1] * i;
	}

	if (num == 1) {
		long k, result;
		cin >> k;
		 
		for (int i = N; i >= 1; i--) {
			if (arr[i - 1] > k) {
				result = GetNum(1);
			}
			else {
				result = GetNum((k - 1) / arr[i - 1] + 1);
				k = (k - 1) % arr[i - 1] + 1;
			}
			cout << result << ' ';
		}
	}
	else {
		long num, result = 1;
		for (int i = N; i >= 1; i--) {
			cin >> num;
			result += arr[i - 1] * (GetIdx(num) - 1);
		}
		cout << result;
	}
}