#include <cstring>
#include <iostream>
#include <queue>

#define MAX 1000
// 불이 아예 나지 않은 경우인 
// 79line -> !vis[ny][nx] 조건을 고려하지 않아 1솔 실패
using namespace std;

typedef struct {
	int y, x;
}pos_t;
queue<pos_t> q;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int w, h;
char map[MAX][MAX];
int vis[MAX][MAX];
int mov[MAX][MAX];

void Bfs1() {
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if(map[ny][nx] == '#') continue;
			
			if(!vis[ny][nx] || vis[ny][nx] > vis[y][x] + 1) {
				q.push({ny, nx});
				vis[ny][nx] = vis[y][x] + 1;
			}

		}
	}

/*
	cout << "fire" << '\n';
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
*/

}

void Bfs2(int r, int c) {
	
	queue<pos_t> q2;
	q2.push({r, c});
	mov[r][c] = true;
	
	while(!q2.empty()) {
		int y = q2.front().y;
		int x = q2.front().x;
		q2.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= h || nx >= w) {
				cout << mov[y][x] << '\n';
				return;
			}
			if(map[ny][nx] == '#') continue;

			if(!mov[ny][nx] && (!vis[ny][nx] || mov[y][x] + 1 < vis[ny][nx])) {
				q2.push({ny, nx});
				mov[ny][nx] = mov[y][x] + 1;
			}
		}
	}

/*
	cout << "move" << '\n';
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) {
			cout << mov[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
*/

	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--) {

		pos_t start;
		memset(vis, 0x00, sizeof(vis));
		memset(mov, 0x00, sizeof(mov));
		
		cin >> w >> h;
		for(int i=0; i<h; ++i) {
			for(int j=0; j<w; ++j) {

				cin >> map[i][j];
				if(map[i][j] == '*') {
					q.push({i, j});
					vis[i][j] = 1;					
				}
				else if(map[i][j] == '@') start = {i, j}; 
				else; 
			}
		}
			
		Bfs1();
		Bfs2(start.y, start.x);
	}

	return 0;
}
