#include <algorithm>
#include <iostream>
#include <deque>

#define INF 2147000000
#define MAX 501

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; 

typedef struct {
	int y, x;
}pos_t;

int map[MAX][MAX];
int check[MAX][MAX];

void Bfs(int r, int c) {
	fill(&check[0][0], &check[MAX - 1][MAX], INF);
	
	deque<pos_t> dq;
	dq.push_front({0, 0});
	check[0][0] = 0;
	
	while(!dq.empty()) {
		int y = dq.front().y;
		int x = dq.front().x;
		dq.pop_front();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && nx>=0 && ny<=r && nx<=c) {
				if(map[ny][nx] > -1) {
					if(check[y][x] + map[ny][nx] < check[ny][nx]) {
						check[ny][nx] = check[y][x] + map[ny][nx];
						
						if(map[ny][nx])	dq.push_back({ny, nx});
						else			dq.push_front({ny, nx});
					}
				}
				
			}
		}
	}
	
	if(check[r][c] == INF)	cout << -1;
	else					cout << check[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n;
	for(int k=0; k<n; k++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 < y2) {
			if(x1 < x2) {
				for(int i=y1; i<=y2; i++)
					for(int j=x1; j<=x2; j++)
						map[i][j] = 1;
			}
			else {
				for(int i=y1; i<=y2; i++)
					for(int j=x2; j<=x1; j++)
						map[i][j] = 1;
			}
		}
		else {
			if(x1 < x2) {
				for(int i=y2; i<=y1; i++)
					for(int j=x1; j<=x2; j++)
						map[i][j] = 1;
			}
			else {
				for(int i=y2; i<=y1; i++)
					for(int j=x2; j<=x1; j++)
						map[i][j] = 1;
			}
		}
	}
	
	cin >> m;
	for(int k=0; k<m; k++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 < y2) {
			if(x1 < x2) {
				for(int i=y1; i<=y2; i++) {
					for(int j=x1; j<=x2; j++) {
						map[i][j] = -1;
					}
				}		
			}
			else {
				for(int i=y1; i<=y2; i++) {
					for(int j=x2; j<=x1; j++) {
						map[i][j] = -1;
					}
				}
			}
		}
		else {
			if(x1 < x2) {
				for(int i=y2; i<=y1; i++) {
					for(int j=x1; j<=x2; j++) {
						map[i][j] = -1;
					}
				}
			}
			else {
				for(int i=y2; i<=y1; i++) {
					for(int j=x2; j<=x1; j++) {
						map[i][j] = -1;						
					}
				}
			}
		}
	}
	
	Bfs(500, 500);
	
	return 0;
}
