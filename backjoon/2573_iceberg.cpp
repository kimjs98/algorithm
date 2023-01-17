#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 301
using namespace std;

typedef struct {
	int y, x;

}pos_t;
vector<pos_t> v_ice;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int map[MAX][MAX];
bool check[MAX][MAX];

int n, m;

void Melting(int y, int x) {
	
	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
			
		if(ny>=0 && nx>=0 && ny<n && nx<m) {		
			if(map[ny][nx] == 0 && !check[ny][nx]) {
				map[y][x]--;
				
				if(!map[y][x])	break;
			}
		}
	}
}


void Bfs(int r, int c) {
	queue<pos_t> q;
	q.push({r, c});
	check[r][c] = true;

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		v_ice.push_back({y, x});
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<n && nx<m) {
				if(!check[ny][nx] && map[ny][nx]) {
					q.push({ny, nx});
					check[ny][nx] = true;
					
				}
			}
		}
	}
	
}

void CheckIceberg() {
	int cnt = 0, year = 0;
	while(1) {
		
		cnt = 0;
	
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!check[i][j] && map[i][j]) {
					Bfs(i, j);
					cnt++;
				}
			}
		}
		
		if(v_ice.empty()) {
			cout << 0;
			break;
		}
		else if(cnt > 1) {
			cout << year;
			break;
		}
		
		for(int i=0; i<v_ice.size(); i++) {
			Melting(v_ice[i].y, v_ice[i].x);
		}

		year++;
				
		v_ice.clear();
		memset(check, false, sizeof(check));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}

	CheckIceberg();
	
	return 0;
}
