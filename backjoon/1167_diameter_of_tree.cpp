#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001
using namespace std;

int n, ans;
bool check[MAX];

typedef struct {
	int node;
	int weight;
}node_t;
vector<node_t> v_node[MAX];

int max_val, long_node;
void Dfs(int node, int sum) {
	if(sum > max_val) {
		max_val = sum;
		long_node = node;
	}
	
	check[node] = true;
	for(int i=0; i<v_node[node].size(); i++) {
		int next = v_node[node][i].node;
		if(!check[next]) {
			int w = v_node[node][i].weight;
			Dfs(next, sum + w);
		}
	}

}

void FineDiameter() {
	Dfs(1, 0);
	memset(check, false, sizeof(check));
	max_val = 0;
	
	Dfs(long_node, 0);
	cout << max_val;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		while(1) {
			int e, w;
			cin >> e;

			if(e == -1)	break;
			cin >> w;
			v_node[v].push_back({e, w});
		}
	}

	FineDiameter();

	return 0;
}
