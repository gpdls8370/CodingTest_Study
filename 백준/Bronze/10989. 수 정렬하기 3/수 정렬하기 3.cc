#include<iostream>
#include<vector>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr(10001 , 0);

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		arr[num]++;
	}

	for(int i=0;i<=10000;i++){
		for(int j=0;j<arr[i];j++){
			cout << i << '\n';
		}
	}
}
