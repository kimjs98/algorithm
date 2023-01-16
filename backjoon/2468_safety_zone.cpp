#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX 101
using namespace std;

typedef struct {
	int y, x;
	
}pos_t;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int map[MAX][MAX];
bool check[MAX][MAX];
int n, h, ans;

void Bfs(int y, int x, int height) {
	queue<pos_t> q;
	q.push({y, x});
	check[y][x] = true;
	
	while(!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<n && nx<n) {
				if(map[ny][nx] > height && !check[ny][nx]) {
					q.push({ny, nx});
					check[ny][nx] = true;
				}
			}
		}		
	}
}

void CalSafetyZone(int height) {
	memset(check, false, sizeof(check));
	int cnt = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!check[i][j] && map[i][j] > height) {

				Bfs(i, j, height);
				cnt++;
			}
		}
	}

	ans = max(ans, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	
	
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
			h = max(h, map[i][j]);
		}
	}
	
	ans = 1;
	for(int i=1; i<h; i++) {
		CalSafetyZone(i);
	}
	cout << ans;
	
	return 0;
}
