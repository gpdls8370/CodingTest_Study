#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a , b;
string str;
vector<vector<int>> dp;
void GetStr(int i , int j);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;

	dp.resize(a.length() + 1 , vector<int>(b.length() + 1, 0));

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}

	GetStr(a.length() , b.length());

	cout << dp[a.length()][b.length()] << '\n';

	for (int i = str.length() - 1; i >= 0; i--) {
		cout << str[i];
	}
}

void GetStr(int i , int j) {
	if (i == 0 || j == 0) return;

	if (a[i - 1] == b[j - 1]) {
		str += a[i - 1];
		GetStr(i - 1 , j - 1);
	}
	else {
		if (dp[i][j - 1] > dp[i - 1][j]) {
			GetStr(i , j - 1);
		}
		else {
			GetStr(i - 1 , j);
		}
	}

}