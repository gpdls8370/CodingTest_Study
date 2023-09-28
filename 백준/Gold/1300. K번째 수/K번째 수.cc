#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; 
	long k;
	cin >> N >> k;

	long min = 1;
	long max = k;
	long temp = 0;

	while(min <= max){
		long mid = (min + max) / 2;
		long count = 0;

		for(int i=1;i<=N;i++){
			long num = mid / i;
			count += (num > N) ? N : num;
		}

		if (count < k) min = mid + 1;
		else{
			temp = mid;
			max = mid - 1;
		}
	}

	cout << temp;
}