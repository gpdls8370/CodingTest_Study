#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M , N;
	cin >> M >> N;

	vector<bool> isPrime(N + 1 , true);

	isPrime[1] = false;

	for(int i=2;i<N+1;i++){
		if(isPrime[i]){
			int k = 2;
			while(i*k <= N){
				isPrime[i * k] = false;
				k++;
			}
		}
	}

	for(int i=M;i<N+1;i++){
		if (isPrime[i]) cout << i << '\n';
	}
}