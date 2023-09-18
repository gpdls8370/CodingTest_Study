#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);

	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	sort(arr.begin() , arr.end());

	int sum = arr[0];

	for(int i=1;i<N;i++){
		arr[i] += arr[i - 1];
		
		sum += arr[i];
	}

	cout << sum;
}