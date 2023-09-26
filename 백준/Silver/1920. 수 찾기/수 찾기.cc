#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N;

	arr.resize(N);

	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	sort(arr.begin() , arr.end());
	cin >> M;
	
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		
		int start = 0;
		int end = N - 1;
		int mid;
		int result = 0;

		while(start <= end){
			mid = (start + end) / 2;
			if(arr[mid] == num){
				result = 1;
				break;
			}
			else if(arr[mid] > num){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		
		cout << result << '\n';
	}
}