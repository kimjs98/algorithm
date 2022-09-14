#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

int map[MAX][MAX];
bool check[MAX][MAX];


int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};	// 0 ,1 ,2 ,3 

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};

int n, m;
int r, c, d;

typedef struct{
	int y;
	int x;

}point;

queue<point> q;

int Bfs() {
	
	q.push({c, r});
	check[c][r] = true;
	
	int cnt = 1;
	while(!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		
		bool flag = false;	
		for(int i=0; i<4; i++) {
			
			/* 왼쪽으로 회전 */
			d = (d+3) % 4;
			
			/* 전진할 방향 */
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if(map[ny][nx] == 0 && check[ny][nx] == false ) { 
				
				q.push({ny, nx});	  
				cnt++;
				check[ny][nx] = true;
					
				flag = true;
				break;	
			}

		}
		
		if(flag == false) {
			
			int bx = x - dx[d];
			int by = y - dy[d];
			
			if(map[by][bx] == 0)
				q.push({by, bx});
		}
	}	
	
	return cnt;
}

int main() {
	
	/* input */
	cin >> n >> m;
	cin >> r >> c >> d;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}
	cout << Bfs();
	
	return 0;
}
