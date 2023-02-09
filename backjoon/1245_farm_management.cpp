#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};


bool check[100][70];
int map[100][70];
int n, m;

typedef struct {
	int y, x;
}pos_t;

typedef struct {
	int y, x;
	int height;

}state_t;

struct cmp {
	bool operator()(state_t a, state_t b) {
		return a.height < b.height;
	}
};
priority_queue<state_t, vector<state_t>, cmp> pq;

bool Bfs(state_t top) {
	
	if(check[top.y][top.x])	return 0;

	check[top.y][top.x] = true;
	queue<pos_t> q;
	q.push({top.y, top.x});

	bool flag = true;
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;		
		q.pop();
		
		for(int i=0; i<8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<n && nx<m) {
				
				if(map[ny][nx] > map[y][x]) flag = false;
				
				if(!check[ny][nx]) {
					if(map[ny][nx] == map[y][x]) {
						q.push({ny, nx});
						check[ny][nx] = true;
					}
				}
			}
		}
	}

	return flag;
}

void CheckMountainTop() {
	int ans = 0;
	while(!pq.empty()) {		
		state_t tmp = pq.top();		//	높은 순서대로 pop 
		pq.pop();

		ans += Bfs(tmp);
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j])	pq.push({i, j, map[i][j]});
		}
	}
	CheckMountainTop();

	return 0;
}

