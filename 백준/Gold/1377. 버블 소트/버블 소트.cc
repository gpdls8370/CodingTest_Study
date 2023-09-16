#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int , int>> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin() , arr.end());
	
	int max = 0;

	for(int i=0;i<N;i++){
		int move = arr[i].second - i;

		if (move > max) max = move;
	}

	cout << max + 1;
}