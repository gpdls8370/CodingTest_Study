#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> link;
void Union(int a , int b);
int Find(int a);

struct edge{
	int s , e , v;

	bool operator()(edge a, edge b){
		return a.v > b.v;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V , E;
	cin >> V >> E;

	priority_queue<edge , vector<edge> , edge> que;
	link.resize(V + 1);

	for (int i = 0; i < E; i++) {
		edge e;
		cin >> e.s >> e.e >> e.v;
		que.push(e);
	}

	for (int i = 1; i <= V; i++) {
		link[i] = i;
	}

	int count = 0;
	int result = 0;

	while (count < V - 1) {
		edge e = que.top();
		que.pop();
	
		if (Find(e.s) != Find(e.e)) {
			Union(e.e, e.s);
			result += e.v;
			count++;
		}
	}

	cout << result;
}

void Union(int a, int b){
	link[Find(b)] = Find(a);
}

int Find(int a) {
	if (link[a] != a){
		link[a] = Find(link[a]);
	}

	return link[a];
}