#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int num);
void BFS(int num);
vector<bool> visited;
vector<vector<int>> link;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N , M, V;
	cin >> N >> M >> V;

	visited.resize(N+1);
	link.resize(N+1);

	for(int i=0;i<M;i++){
		int a , b; 
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	for(int i=1;i<=N;i++){
		sort(link[i].begin() , link[i].end());
	}

	DFS(V);
	cout << '\n';
	fill(visited.begin() , visited.end() , false);
	BFS(V);
}

void DFS(int num){
	visited[num] = true;
	cout << num << ' ';

	for(int a : link[num]){
		if (!visited[a]) DFS(a);
	}
}

void BFS(int num){
	queue<int> que;
	que.push(num);
	visited[num] = true;

	while (!que.empty()) {
		int a = que.front();
		que.pop();
		cout << a << ' ';
		
		for (int b : link[a]) {
			if (!visited[b]) {
				que.push(b);
				visited[b] = true;
			}
		}
	}
}