#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX	50

int n, m;
int map[MAX][MAX];
int check[MAX][MAX];

bool visit[MAX][MAX];

int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

typedef struct {
	int y, x;
	
}yx;
queue<yx> q;

void Bfs() {

	int temp = 0;
	while(!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for(int i=0; i<8; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny>=0 && nx>=0 && ny<n && nx<m) {
				if(!map[ny][nx]) {
					
					q.push({ny, nx});
					map[ny][nx] = map[y][x] + 1;
					temp = map[ny][nx];
				}
			}
		}
	}

	cout << temp - 1;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j])	q.push({i, j});
		}
	}
	
	Bfs();

	return 0;
}
