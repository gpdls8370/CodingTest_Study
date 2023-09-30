#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int sum = 0;
	int minus = 1;
	string num;

	for(int i=0;i<str.length();i++){
		if(str[i] == '+' || str[i] == '-'){
			sum += stoi(num) * minus;
			if (str[i] == '-') minus = -1;
			num = "";
		}
		else{
			num += str[i];
		}
	}
	sum += stoi(num) * minus;

	cout << sum;
}