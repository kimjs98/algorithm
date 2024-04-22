#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 1000 
using namespace std;

typedef struct {
	int y, x;
	bool broken;
}pos_t;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};


int map[MAX][MAX];
int vis[MAX][MAX][2];

// vis[i][j][0]; -> 벽을 부수지 않고 i, j까지 오는데 걸리는 값.
// vis[i][j][1]; -> 벽을 한개만 부수고 i, j까지 오는데 걸리는 비용.
// i, j가 벽이라서 부수는 경우 포함.

int n, m;

int Bfs() {
	queue<pos_t> q;
	q.push({0, 0, 0});
	
	vis[0][0][0] = vis[0][0][1] = 1;

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		bool broken = q.front().broken;
		q.pop();
		
		if(y == n - 1 && x == m - 1)
			return vis[y][x][broken];
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;

			// 벽이 아니고, 방문한 적이 없는 경우 
			if(!map[ny][nx] && !vis[ny][nx][broken]) {
				
				vis[ny][nx][broken] = vis[y][x][broken] + 1;
				q.push({ny, nx, broken});
			}
			
			// ny, nx를 부수는 경우  
			if(!broken && map[ny][nx] && !vis[ny][nx][1]) {
				vis[ny][nx][1] = vis[y][x][broken] + 1;
				q.push({ny, nx, 1});
			}

		}
	}
	/*
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cout << vis[i][j][0] << ' ';
		}
		cout << '\n';
	}
	
	cout << '\n';
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cout << vis[i][j][1] << ' ';
		}
		cout << '\n';
	}
	*/
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	string str;
	for(int i=0; i<n; ++i) {
		cin >> str;
		for(int j=0; j<m; ++j) {
			map[i][j] = str[j] - '0';
		}
	}

	int ret = Bfs();
	cout << ret;
	
	return 0;
}
