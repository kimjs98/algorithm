#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 10001
using namespace std;

int n, diameter;

typedef struct {
	int node;
	int weight;
}node_t;
vector<node_t> v[MAX];

typedef struct {
	int edge;
	int weight;
}edge_t;

struct cmp {
	bool operator()(edge_t a, edge_t b) {
			return a.weight < b.weight;	
	}
};
priority_queue<edge_t, vector<edge_t>, cmp> pq;

void ExceptionDfs(int num, int sum) {
	if(v[num].empty()) {
		diameter = max(sum, diameter);
		return;
	}

	for(int i=0; i<v[num].size(); i++) {
		int next = v[num][i].node;
		int weight = v[num][i].weight;

		ExceptionDfs(next, sum + weight);
	}
}

void Dfs(int num, int sum, int depth, int edge_num) {
	if(v[num].empty()) {
		//cout << "length : " << sum << '\n';
		if(pq.empty())	pq.push({edge_num, sum});
		else {
			if(pq.top().edge == edge_num) {
				if(sum > pq.top().weight) {
					pq.pop();
					pq.push({edge_num, sum});
				}
			}
			else	pq.push({edge_num, sum});
		}
		return;
	}

	for(int i=0; i<v[num].size(); i++) {
		int next = v[num][i].node;
		int weight = v[num][i].weight;

		if(!depth)	Dfs(next, sum + weight, depth + 1, i);
		else		Dfs(next, sum + weight, depth + 1, edge_num);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for(int i=0; i<n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		v[a].push_back({b, c});
	}

	for(int i=1; i<=n; i++) {
		if(v[i].size() > 1) {
			//cout << "node : " << i << '\n';
			Dfs(i, 0, 0, 0);
			
			int length = 0;
			for(int j=0; j<2; j++) {
				length += pq.top().weight;
				pq.pop();
			}
			diameter = max(length, diameter);
			while(!pq.empty()) pq.pop();
		}
		else {
			if(i == 1)
				ExceptionDfs(i, 0);
		}

	}
	cout << diameter;
	return 0;
}
