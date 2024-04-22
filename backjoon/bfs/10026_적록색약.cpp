#include <cstring>
#include <iostream>
#include <queue>

#define MAX 100
 
using namespace std;

typedef struct {
	int y, x;
}pos_t;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

char map[MAX][MAX];
bool vis[MAX][MAX];

int n;
int cnt[3];

void Bfs(int r, int c) {
	char col = map[r][c];
	vis[r][c] = true;
	
	queue<pos_t> q;
	q.push({r, c});
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(vis[ny][nx] || map[ny][nx] != col) continue;
			
			vis[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	
	if(col == 'R')		cnt[0]++;
	else if(col == 'B')	cnt[1]++;
	else				cnt[2]++;
	
}

void Bfs2(int r, int c) {
	vis[r][c] = true;
	
	queue<pos_t> q;
	q.push({r, c});
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(vis[ny][nx] || map[ny][nx] == 'B') continue;
			
			vis[ny][nx] = true;
			q.push({ny, nx});
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> map[i][j];
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(vis[i][j]) continue;
			
			Bfs(i, j);
		}
	}

	memset(vis, 0x00, sizeof(vis));
	
	int area = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(map[i][j] == 'B') continue;
			if(vis[i][j]) continue;
			
			Bfs2(i, j);
			area++;
		}
	}
	
	cout << cnt[0] + cnt[1] + cnt[2] << ' ' << area + cnt[1];

	return 0;
}
