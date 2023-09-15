#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	stack<int> s;
	string result;

	int next = 1;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i < n;i++) {
		int target = arr[i];

		while (next <= target) {
			s.push(next++);
			result += "+\n";
		}

		if (s.top() > target) {
			cout << "NO";
			return 0;
		}

		s.pop();
		result += "-\n";
	}

	cout << result;

	return 0;
}