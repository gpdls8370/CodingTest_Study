#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& arr , int start , int end , int K);
int partition(vector<int>& arr , int start , int end);

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , K;
	cin >> N >> K;

	vector<int> arr(N);

	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	quickSort(arr , 0 , N - 1 , K - 1);

	cout << arr[K - 1];
}

void quickSort(vector<int> &arr, int start, int end, int K){
	int pivot = partition(arr , start , end);

	if (pivot == K) return;
	else if (pivot > K) quickSort(arr , start , pivot - 1 , K);
	else quickSort(arr , pivot + 1 , end , K);
}

int partition(vector<int> &arr, int start, int end){

	if(start + 1 ==end){
		if (arr[start] > arr[end]) swap(arr[start] , arr[end]);
		return end;
	}

	int middle = (start + end) / 2;

	swap(arr[start] , arr[middle]);

	int pivot = arr[start];

	int left = start + 1;
	int right = end;

	while(left <= right){
		while (arr[right] > pivot && right > 0) right--;
		while (arr[left] < pivot && left < arr.size() - 1) left++;

		if (left <= right) swap(arr[left++] , arr[right--]);
	}

	swap(arr[start] , arr[right]);

	return right;
}