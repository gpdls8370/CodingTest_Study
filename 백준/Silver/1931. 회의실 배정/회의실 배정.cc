#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(pair<int , int> a , pair<int , int> b) {
		if (a.second == b.second) 
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<pair<int , int> , vector<pair<int , int>> , cmp> time;

	for(int i=0;i<N;i++){
		int a , b;
		cin >> a >> b;
		time.push(make_pair(a , b));
	}

	int start = 0;
	int count = 0;

	while(!time.empty()){
		if(time.top().first >= start){
			count++;
			start = time.top().second;
		}
		time.pop();
	}

	cout << count;
}