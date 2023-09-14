#include <iostream>
#include <vector>
using namespace std;

int target[4];
int check[4];
void Add(char c);
void Remove(char c);
void Check();
int result = 0;

int main() {

	int total, range;
	cin >> total >> range;

	string S;
	cin >> S;

	cin >> target[0] >> target[1] >> target[2] >> target[3];

	int start = 0;

	for (int i = 0; i < range; i++) {
		Add(S[i]);
	}
	Check();

	for (int start = 0; start < total - range; start++) {
		Remove(S[start]);
		Add(S[start + range]);
		Check();
	}

	cout << result;
}

void Add(char c) {
	if (c == 'A') { check[0]++; }
	else if (c == 'C') { check[1]++; }
	else if (c == 'G') { check[2]++; }
	else if (c == 'T') { check[3]++; }
}

void Remove(char c) {
	if (c == 'A') { check[0]--; }
	else if (c == 'C') { check[1]--; }
	else if (c == 'G') { check[2]--; }
	else if (c == 'T') { check[3]--; }
}

void Check() {
	for (int i = 0; i < 4; i++) {
		if (check[i] < target[i]) return;
	}
	result++;
	return;
}