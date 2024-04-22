#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 100
using namespace std;
// time limit : 2s / n = 100

typedef struct {
	int y, x;
}pos_t;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int map[MAX][MAX];
int dis[MAX][MAX];
bool vis[MAX][MAX];

int n, ans;

void Bfs(int r, int c, int num) {
	queue<pos_t> q;
	q.push({r, c});
	vis[r][c] = 1;
	map[r][c] = num;
	
	while(!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(vis[ny][nx] || !map[ny][nx]) continue;
			// 이미 방문했거나 0인 경우 
			q.push({ny, nx});
			
			vis[ny][nx] = true;
			map[ny][nx] = num;
		}		
	}

}

void Bfs2(int r, int c) {
	for(int i=0; i<n; ++i)
		fill(dis[i], dis[i] + n, -1);
	
	queue<pos_t> q;
	q.push({r, c});
	dis[r][c] = 0;
	
	bool escape = false;
	while(!q.empty() && !escape) {

		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(dis[ny][nx] >= 0 || map[r][c] == map[ny][nx]) continue;

			if(map[ny][nx] && map[ny][nx] != map[r][c]) {
				ans = min(ans, dis[y][x]);
				//while(!q.empty()) q.pop();
				
				escape = true;
				break;
			}
			
			dis[ny][nx] = dis[y][x] + 1;
			q.push({ny, nx});
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) cin >> map[i][j];

	int cnt = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(!map[i][j] || vis[i][j]) continue;
			
			Bfs(i, j, ++cnt);
		}
	}
/*
	cout << '\n';
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
*/
	ans = 2147000000;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(!map[i][j]) continue;
			
			Bfs2(i, j);
		}
	}
	cout << ans;

	return 0;
}
