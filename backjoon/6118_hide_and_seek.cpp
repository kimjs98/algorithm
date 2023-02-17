#include <iostream>
#include <vector>
#include <queue>

#define N_MAX 20001

using namespace std;

int n, m;
int visit[N_MAX];
vector<int> v[N_MAX];

void Bfs() {
	queue<int> q;
	visit[1] = true;
	q.push(1);

	int max_dist;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i=0; i<v[x].size(); i++) {
			int next = v[x][i];
			if(!visit[next]) {
				q.push(next);
				visit[next] = visit[x] + 1;
				max_dist = visit[next];
			}
		}
	}

	int num, dist;
	int cnt = 0;
	
	bool flag = false;
	for(int i=1; i<=n; i++) {
		
		if(visit[i] == max_dist) {
			cnt++;
			
			if(!flag) {
				flag = true;
				num = i;
			}
		}
	}
	cout << num << ' ' << max_dist - 1 << ' ' << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);			
	}
	Bfs();
	
	return 0;
}
