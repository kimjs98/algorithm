#include <cstring>
#include <iostream>
#include <queue>

//#define DEBUG
#define MAX 3001
using namespace std;

vector<int> v[MAX];
bool check[MAX];	// 방문 체크 배열
int pre_node[MAX];	// 이전 방문 노드
bool cycle_node[MAX];
int n;
bool cycle;
queue<int> q_cycle;

void Bfs() {
	memset(check, false, sizeof(check));
	int dist[n + 1] = { 0, };
	while(!q_cycle.empty()) {
		
		int node = q_cycle.front();
		q_cycle.pop();
		
		for(int i=0; i<v[node].size(); i++) {
			int next = v[node][i];
			
			if(!check[next]) {
				if(!cycle_node[next]) {	// 다음 노드가 사이클이 아닌 경우  
					q_cycle.push(next);
					
					check[next] = true;
					dist[next] = dist[node] + 1;				
				}	
			}
			
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << dist[i] << ' ';
	}
	
}
void LoopCheck(int node) {
	if(cycle)	return;

	check[node] = true;
	for(int i=0; i<v[node].size(); i++) {
		
		int next = v[node][i];

		if(!check[next]) {		// 방문하지 않은 노드
			pre_node[next] = node;
			LoopCheck(next);		
		}
		else {					// 방문한 노드
			if(next != pre_node[node]) {
				cycle = true;		
#ifdef DEBUG
				cout << "cycle. present node : " << node << '\n';
				cout << "next node : " << next << '\n';
				cout << "pre node : "<< pre_node[node] << '\n';
#endif
				
				int tmp = node;
				while(tmp != pre_node[next]) {
					cycle_node[tmp] = true;			
					q_cycle.push(tmp);
					tmp = pre_node[tmp];
				}
				
				return;
			}
		}
		
		if(cycle)	return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	LoopCheck(1);
	Bfs();

	return 0;
}
