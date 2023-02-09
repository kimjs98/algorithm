#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;

int n;
bool check[MAX];
int parent_node[MAX];
vector<int> v[MAX];

void Dfs(int node) {
	check[node] = true;
	for(int i=0; i<v[node].size(); i++) {
		int next = v[node][i];
		if(!check[next]) {
			parent_node[next] = node;
			Dfs(next);
		}
	}
}

void Bfs() {
	queue<int> q;
	q.push(1);
	check[1] = true;
	
	while(!q.empty()) {
		
		int x = q.front();
		q.pop();
		
		for(int i=0; i<v[x].size(); i++) {
			
			int next = v[x][i];
			if(!check[next]) {
				q.push(next);
				check[next] = true;
				parent_node[next] = x;
			}
		}	
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for(int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	Bfs();
	//Dfs(1);
	
	for(int i=2; i<=n; i++) {
		cout << parent_node[i] << '\n';
	}
	
	return 0;
}
