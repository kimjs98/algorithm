#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 501
using namespace std;

typedef struct {
	int y, x;
}pos_t;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1 ,0};

int map[MAX][MAX];
bool check[MAX][MAX];

int n, m;

int Bfs(int r, int c) {
	queue<pos_t> q;
	q.push({r, c});
	check[r][c] = true;
	
	int size = 1;
	while(!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny >=0 && nx >=0 && ny<n && nx<m) {
				if(!check[ny][nx] && map[ny][nx]) {
					check[ny][nx] = true;
					q.push({ny, nx});
					size++;
				}
			}	
		}
	}
	
	return size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}
	
	int ans = 0, num = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!check[i][j] && map[i][j]) {
				int size = Bfs(i, j);
				ans = max(ans, size);
				num++;
			}
		}
	}
	
	cout << num << '\n' << ans;
	
	return 0;
}
