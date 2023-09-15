#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		int a2 = abs(a);
		int b2 = abs(b);

		if (a2 == b2) return a > b;

		return a2 > b2;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, compare> q;

	for(int i=0;i<N;i++){
		int a;
		cin >> a;

		if (a != 0) {
			q.push(a);
		}
		else{
			if(q.empty()){
				cout << "0\n";
			}
			else{
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
}
