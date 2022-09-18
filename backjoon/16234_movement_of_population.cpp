#include <algorithm>
#include <cstring> 
#include <iostream>
#include <queue>

using namespace std;

#define MAX 51

int map[MAX][MAX];
bool check[MAX][MAX];
bool un[MAX][MAX];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int n, l, r;

int cnt;

typedef struct{
	int y,x;
}yx;

queue<yx> q;

bool Bfs(int y, int x) {

	q.push({y, x});
	check[y][x] = true;
	un[y][x] = true;

	int total = map[y][x];
	int union_cnt = 1;
	
	bool flag = false;
	while(!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(nx>=0 && ny>=0 && nx<n && ny<n) {
				
				int diff = abs(map[ny][nx] - map[y][x]);	// 두 나라 간의 인구수 차이 
				if( ( diff>=l && diff<=r )  && !un[ny][nx] ) {
					
					q.push({ny,nx});
					check[ny][nx] = true;
					un[ny][nx] = true;
					
					union_cnt++;
					total += map[ny][nx]; 
					
					flag = true;
				}
			}
		}
	}	
	
	if(flag) {
		/* 인구이동이 일어난 경우 인구수 업데이트 */
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(check[i][j]) {
					map[i][j] = total/union_cnt;
				}		
			}
		}	
	}
	
	memset(check, false, sizeof(check));
	
	return flag;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	/* input */
	cin >> n >> l >> r;
	
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0, temp = 0;
	while(1) {
		/* cycle */
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				if(!un[i][j]){
					temp += Bfs(i, j);
					
				}
			}
		}	
		
		memset(un, false, sizeof(un));
				
		if(temp) {
			ans++;
			temp = 0;
		}
		else
			break;
	}
	cout << ans;
	
	return 0;
}
