#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> result(N, -1);
	vector<int> nums(N);
	stack<int> s;

	for (int i = 0;i < N;i++) {
		cin >>nums[i];

		while (!s.empty() && nums[s.top()] < nums[i]) {
			result[s.top()] = nums[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0;i < N;i++) {
		cout << result[i] << ' ';
	}
}