#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[1000];
	
	int max =0, sum = 0;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];

		if (arr[i] > max) {
			max = arr[i];
		}

		sum += arr[i];
	}

	cout << sum * 100.0 / max / N;
}