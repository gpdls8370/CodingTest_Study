#include <iostream>
#include <vector>
using namespace std;

void DFS(int num, int depth);
vector<bool> visited;
vector<vector<int>> link;
bool result = false;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M;
	cin >> N >> M;

	visited.resize(N);
	link.resize(N);

	for(int i=0;i<M;i++){
		int a , b;
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	for(int i=0;i<N;i++){
		if (!visited[i] && !result) {
			DFS(i, 0);
		}
	}

	cout << result ? 1 : 0;
}

void DFS(int num, int depth){
	if (visited[num] || result) return;
	
	visited[num] = true;
	depth++;

	if(depth == 5) {
		result = true;
		return;
	}

	for(int a : link[num]){
		if (!visited[a]) DFS(a, depth);
	}

	//DFS 다 끝나고 false로 다시 초기화
	visited[num] = false;
}