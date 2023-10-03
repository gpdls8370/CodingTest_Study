#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long min, max;
	cin >> min >> max;

	vector<bool> isSq(max - min + 1 , false);
	int count = 0;

	for(long i=2;i*i<=max;i++){
		long pow = i * i;
		long k = min / pow;
		
		if (min % pow != 0) k++;

		while (pow * k <= max){
			if(!isSq[pow * k - min]){
				isSq[pow * k - min] = true;
				count++;
			}
			k++;
		}
	}

	cout << max - min - count + 1;
}