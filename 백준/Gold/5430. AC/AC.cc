#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	string p , str;
	deque<int> que;
	int n , num;
	for (int i = 0; i < T; i++) {
		cin >> p >> n >> str;
		que.clear();
		num = 0;

		if (n != 0) {
			for (int j = 1; j < str.length() - 1; j++) {
				if (str[j] != ',') {
					num = num * 10 + (str[j] - '0');
				}
				else {
					que.push_back(num);
					num = 0;
				}
			}
			que.push_back(num);
		}

		bool error = false;
		bool rev = false;

		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				rev = !rev;
			}
			else{
				if (que.empty()) {
					cout << "error\n";
					error = true;
					break;
				}
				rev ? que.pop_back() : que.pop_front();
			}
		}

		if (!error) {
			if (que.empty()) {
				cout << "[]\n";
			}
			else {
				cout << '[';
				if (rev) reverse(que.begin() , que.end());
				while (!que.empty())
				{
					cout << que.front();
					que.pop_front();
					if (que.size() > 0) cout << ',';
				}
				cout << "]\n";
			}
		}
	}
}