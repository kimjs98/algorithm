#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001 
using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

typedef struct {
	int y, x;
}pos_t;

int map[MAX][MAX];
int path[MAX][MAX];

bool check[MAX][MAX];
int n, m;

queue<pos_t> q1, q2;
void Bfs() {

	// BFS fire
	while(!q1.empty()) {
		
		int y = q1.front().y;
		int x = q1.front().x;
		q1.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(map[ny][nx] == -1) continue;
			if(ny > 0 && nx > 0 && ny <= n && nx <= m) {
				
				map[ny][nx] = map[y][x] + 1;
				q1.push({ny, nx});
			}
		}
	}
	
	cout << "map" << '\n';
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			char c;
			cin >> c;
			
			if(c == '#') 		map[i][j] = -1;
			else if(c == 'J') 	q2.push({i, j});
			else if(c == 'F') 	q1.push({i, j});
			else;

		}
	}
	
	Bfs();
	
	return 0;
}
