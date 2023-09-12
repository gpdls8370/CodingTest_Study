#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;

	string str;
	cin >> str;

	int sum = 0;

	for (int i=0;i<N;i++){
		sum += str[i] - '0';
	}

	cout << sum;
}