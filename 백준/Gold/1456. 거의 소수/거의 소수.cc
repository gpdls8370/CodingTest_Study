#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long A , B;
	cin >> A >> B;
	
	long pMax = sqrt(B);
	vector<bool> isPrime(pMax + 1 , true);

	isPrime[1] = false;

	for(long i=2;i<=sqrt(pMax);i++){
		if (isPrime[i]) {
			long k = 2;
			while (i * k <= pMax) {
				isPrime[i * k] = false;
				k++;
			}
		}
	}

	long count = 0;

	for(long i=2;i<=pMax;i++){
		if(isPrime[i]){
			long k = 2;
			while(pow(i , k) <=B){
				if (pow(i , k) < A) {
					k++; 
					continue;
				}
				count++;
				k++;
			}
		}
	}

	cout << count;
}