#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, m, ans;

char map[50][50];
int dist[50][50];
bool check[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void Dfs(int y, int x, int depth, char color) {
	
	if(check[y][x] == true) {

		if(depth - dist[y][x] >=3) {
			ans = 1;
			return;
		}	
		else
			return;
		
	}
	
	dist[y][x] = depth;
	
	check[y][x] = true;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && ny>=0 && nx<m && ny<n) {
			if( map[ny][nx] == color ) {
				Dfs(ny, nx, depth+1, color);	
			}
		}
	}	
}

int main() {
	
	cin >> n >> m;
	
	string str;
	for(int i=0; i<n; i++) {
		cin >> str;
		for(int j=0; j<m; j++) {
			map[i][j] = str[j] - '\0';
		}
	}
	
	ans = 0;
	for(int i=0; i<n; i++) {	
		for(int j=0; j<m; j++) {
			
			if(!check[i][j] == true) {	
				memset(dist, false, sizeof(dist));
				Dfs(i, j, 0, map[i][j]);
			
			}
			
		}
	}

	if(ans)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}
