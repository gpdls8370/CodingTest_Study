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

	for(int i=0;i<N;i++){
		cout << arr[i] << '\n';
	}
}