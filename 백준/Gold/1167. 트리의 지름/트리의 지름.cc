#include <iostream>
#include <vector>
using namespace std;

typedef pair<int , int> edge;
void DFS(int num, int dist);
vector<vector<edge>> link;
vector<bool> visited;
vector<int> dist;
int N , M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	link.resize(N + 1);
	visited.resize(N + 1);
	dist.resize(N + 1);

	for(int i=1;i<=N;i++){
		int a , b , d;
		cin >> a;
		while(true){
			cin >> b;
			if (b == -1) break;
			cin >> d;
			link[a].push_back(edge(b , d));
		}
	}

	int result = 0;
	int index = 1;

	for(int a=0;a<2;a++){
		DFS(index , 0);
		fill(visited.begin() , visited.end() , false);

		for (int i = 1; i <= N; i++) {
			if (dist[i] > result) {
				result = dist[i];
				index = i;
			}
		}
	}

	cout << result;
}

void DFS(int num, int totDist){
	bool end = true;
	
	visited[num] = true;
	dist[num] = totDist;

	for(edge e : link[num]){
		if(!visited[e.first]){
			DFS(e.first , totDist + e.second);
		}
	}
}

