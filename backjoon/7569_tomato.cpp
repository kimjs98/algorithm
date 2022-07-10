#include <iostream>
#include <queue>

using namespace std;

#define MAX 101
int m,n,h;

int map[MAX][MAX][MAX];
int check[MAX][MAX][MAX];

int dx[] = {0,-1,0,0,1,0};
int dy[] = {0,0,-1,0,0,1};
int dz[] = {1,0,0,-1,0,0};

typedef struct {
	int x;
	int y;
	int z;
} xyz;

queue<xyz> q;

void Bfs() {
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		
		q.pop();
		
		for(int i=0; i<6; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if(nx>=0 && ny>=0 && nz>=0 && nx<m && ny<n && nz<h) {
				if( map[nz][ny][nx] == 0 && check[nz][ny][nx] == 0) {		
					q.push({nx,ny,nz});
					check[nz][ny][nx] = check[z][y][x] + 1;					
				}
			}		
		}
			
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> m >> n >> h;
	for(int i=0; i<h; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				
				cin >> map[i][j][k];
				if(map[i][j][k] == 1) {
					q.push({k,j,i});
					check[i][j][k] = map[i][j][k];
				}
				else if(map[i][j][k] == -1) {
					check[i][j][k] = map[i][j][k];
				}
				else;
			}
		}
	}
	
	Bfs();
	
	int ans = 0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				
				if (ans < check[i][j][k]) {
					ans = check[i][j][k];
				}		
				
				if (check[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	if(ans == 1)
		cout << 0;
	else
		cout << ans-1;

	return 0;
}
