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

	vector<int> plus;
	vector<int> minus;
	int sum = 0;

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if (num < 1) minus.push_back(num);
		else if (num > 1) plus.push_back(num);
		else if (num == 1) sum++;
	}

	sort(plus.begin() , plus.end(), greater<int>());
	sort(minus.begin() , minus.end());

	if(!plus.empty()){
		if (plus.size() % 2 > 0) {
			sum += plus[plus.size() - 1];
		}

		for (int i = 0; i < plus.size() - 1; i += 2) {
			sum += plus[i] * plus[i + 1];
		}
	}
	if(!minus.empty()){
		if (minus.size() % 2 > 0) {
			sum += minus[minus.size() - 1];
		}

		for (int i = 0; i < minus.size() - 1; i += 2) {
			sum += minus[i] * minus[i + 1];
		}
	}

	cout << sum;
}