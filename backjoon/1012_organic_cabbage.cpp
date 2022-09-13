#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

int map[MAX][MAX];
bool check[MAX][MAX]; 

int m,n,k;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void Dfs(int y, int x) {
	
	check[y][x] = true;
	for(int i=0; i<4; i++) {
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<m && ny>=0 && ny<n) {
			if(map[ny][nx] && !check[ny][nx]) {
				Dfs(ny, nx);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	int t;
	cin >> t;
		
	while(t--) {
		
		cin >> m >> n >> k;
		
		int i, j, x, y;
		for(i=0; i<k; i++) {
			cin >> x >> y;
			map[y][x] = true;
		}
		
		int bug = 0;
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				
				if(map[i][j] && !check[i][j]) {
					bug++;
					Dfs(i, j);
				}
			}
		}
		cout << bug << '\n';
		
		memset(map, false, sizeof(map));
		memset(check, false, sizeof(check));
	}
	
	return 0;
}
