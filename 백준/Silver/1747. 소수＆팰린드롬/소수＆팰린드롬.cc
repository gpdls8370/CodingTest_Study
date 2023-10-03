#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool isPNum(int num){
	string str = to_string(num);
	int start = 0;
	int end = str.length() - 1;
	while(start < end){
		if (str[start] != str[end]) return false;
		start++;
		end--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int max = 9999999;
	vector<bool> isPrime(max + 1 , true);

	isPrime[1] = false;

	for(int i=2;i<sqrt(max);i++){
		if(isPrime[i]){
			int k = 2;
			while(i*k <= max){
				isPrime[i * k] = false;
				k++;
			}
		}
	}

	int num = N;

	while(true){
		if(isPrime[num] && isPNum(num)){
			cout << num;
			break;
		}
		num++;
	}
}