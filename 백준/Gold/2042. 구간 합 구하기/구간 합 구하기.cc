#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<long> map;
int start;
void Change(int index , long num);
long Sum(int s , int e);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M , K;
	cin >> N >> M >> K;

	int height = 0;
	int temp = N - 1;
	while (temp != 0) {
		temp /= 2;
		height++;
	}
	start = pow(2 , height);

	map.resize(start * 2 , 0);
	
	for (int i = start; i < N + start; i++) {
		cin >> map[i];
	}

	int j = start * 2 - 1;
	while (j > 1) {
		map[j / 2] += map[j];
		j--;
	}

	for (int i = 0; i < M + K; i++) {
		long a , b , c;
		cin >> a >> b >> c;

		if (a == 1) {
			Change(b , c);
		}
		else {
			cout << Sum(b , c) << '\n';
		}
	}

}

void Change(int index , long num){
	index += start - 1;
	long plus = num - map[index];
	map[index] = num;

	while (index > 1) {
		map[index / 2] += plus;
		index /= 2;
	}
}

long Sum(int s, int e){
	s += start - 1;
	e += start - 1;

	long sum = 0;

	while (s < e) {
		if (s % 2 == 1) {
			sum += map[s];
		}
		if (e % 2 == 0) {
			sum += map[e];
		}

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}

	if (s == e) sum += map[s];

	return sum;
}