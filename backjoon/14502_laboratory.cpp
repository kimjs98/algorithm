#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX	8
int map[MAX][MAX];
int test[MAX][MAX];

int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

typedef struct {
	int x;
	int y;
	
} xy;

queue<xy> q;

int temp,ans;

int Bfs() {	
	memcpy(test,map, sizeof(map));
	
	/* 바이러스 위치 queue에 push */
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {		
			
			if(test[i][j] == 2) {
				q.push({j,i});	
			}
			
		}
	}
	
	while(!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>=0 && ny>=0 && nx<m && ny<n) {
				
				if(test[ny][nx] == 0 ) {
					q.push({nx,ny});
					test[ny][nx] = 2;  
				}
			}
		}
	}
	
	/* 안전 영역 탐색 */
	int res = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {		
			if(test[i][j] == 0) {
				res++;
			}
		}
	}	
	return res;	
}

void Wall(int depth) {
	
	if(depth == 3) {
		
		temp = Bfs();
		if(temp > ans) ans = temp;
		
		return;
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			
			if(!map[i][j]) {
				
				map[i][j] = 1;
				Wall(depth+1);
				map[i][j] = 0;
			}
					
		}
	}
		
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	/* 맵 입력 */
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}
	
	Wall(0);
	cout << ans;

	return 0;
}

