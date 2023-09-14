#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> nums(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int temp = nums[i];
		int start = 0;
		int end = N - 1;

		while (start < end) {
			int sum = nums[start] + nums[end];

			if (sum > temp) {
				end--;
			}
			else if (sum < temp) {
				start++;
			}
			else {
				if (start == i) {
					start++;
				}
				else if (end == i) {
					end--;
				}
				else {
					cnt++;
					break;
				}
			}
		}
	}

	cout << cnt;
}