#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG
#define MAX 10001
using namespace std;

int n, max_val, cnt;
vector<int> v[MAX];

typedef struct {
	int left;
	int right;
}node_t;
node_t node_info[MAX];

typedef struct {
	int level;
	int weight;
}tree_info_t;

struct cmp {
	bool operator()(tree_info_t a, tree_info_t b) {
		if(a.weight == b.weight) {
			return a.level > b.level;
		}
		else return a.weight < b.weight;
	}
};
priority_queue<tree_info_t, vector<tree_info_t>, cmp> pq;

void Dfs(int node, int depth) {
	if(node < 0) {
		max_val = max(max_val, depth);
		return;
	}

	Dfs(node_info[node].left, depth + 1);
	//cout << node << ' ';	// inorder
	v[depth].push_back(++cnt);
	Dfs(node_info[node].right, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	
	int root_node;
	int parent_node[n + 1] = { 0, };
	for(int i=0; i<n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		node_info[a].left = b;
		node_info[a].right = c;
		
		if(b > -1) parent_node[b] = a;
		if(c > -1) parent_node[c] = a;
	}
	for(int i=1; i<=n; i++) {
		if(!parent_node[i]) {
			root_node = i;
			break;	
		}
	}
	Dfs(root_node, 1);
	
	for(int i=1; i<max_val; i++) {
		int weight;
		if(v[i].size() > 1) {
			weight = v[i].back() - v[i].front() + 1;
		}
		else {
			weight = 1;
		}
		
		pq.push({i, weight});
	}
	
	cout << pq.top().level << ' ' << pq.top().weight;
	
#ifdef DEBUG
	cout << '\n';
	for(int i=1; i<max_val; i++) {
		for(int j=0; j<v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	while(!pq.empty()) {
		cout << pq.top().level << ' ' << pq.top().weight << '\n';
		cout << '\n';
		pq.pop();
	}
#endif

	return 0;
}
