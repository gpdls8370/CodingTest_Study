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

	string p , str, num;
	deque<int> que;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> p >> n >> str;
		que.clear();

		if (n != 0) {
			for (int j = 1; j < str.length() - 1; j++) {
				if (str[j] != ',') {
					num += str[j];
				}
				else {
					que.push_back( stoi(num));
					num = "";
				}
			}

			que.push_back(stoi(num));
			num = "";
		}

		bool error = false;
		bool reverse = false;

		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				reverse = !reverse;
			}
			else{
				if (que.empty()) {
					cout << "error\n";
					error = true;
					break;
				}
				reverse ? que.pop_back() : que.pop_front();
			}
		}

		if (!error) {
			if (que.empty()) {
				cout << "[]\n";
			}
			else{
				cout << '[';
				while (que.size() > 1)
				{
					if (!reverse) {
						cout << que.front() << ',';
						que.pop_front();
					}
					else {
						cout << que.back() << ',';
						que.pop_back();
					}
				}

				if (!reverse) {
					cout << que.front() << "]\n";
				}
				else {
					cout << que.back() << "]\n";
				}
			}
		}
	}
}