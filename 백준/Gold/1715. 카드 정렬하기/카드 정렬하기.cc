#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int , vector<int> , greater<int>> card;

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		card.push(num);
	}

	int sum = 0;

	for(int i=0;i<N-1;i++){
		int a = card.top();
		card.pop();
		int b = card.top();
		card.pop();
		sum += a + b;
		card.push(a + b);
	}
	
	cout << sum;
}