#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, m;

char map[50][50];
int dist[50][50];
bool check[50][50];

void Dfs(int y, int x) {
	
	check[y][x] = true;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && ny>=0 && nx<m && ny<n) {
			if(check[ny][nx] == false) {
				
				Dfs(ny, nx);
				
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
	
	for(int i=0; i<n; i++) {	
		for(int j=0; j<m; j++) {
			
			if()
		}
	}
	
	return 0;
}
