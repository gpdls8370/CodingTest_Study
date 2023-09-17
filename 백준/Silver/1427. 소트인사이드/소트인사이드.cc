#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string N;
	cin >> N;

	vector<int> arr;

	for(int i=0;i<N.length();i++){
		arr.push_back(N[i] - '0');
	}

	sort(arr.begin() , arr.end(), compare);

	for(int i=0;i<arr.size();i++){
		cout << arr[i];
	}

}