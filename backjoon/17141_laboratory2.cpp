#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50

int map[MAX][MAX];
int visit[MAX][MAX];
bool virus[MAX][MAX];

bool check[10];

int n, m;
int ans = 2147000000;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

typedef struct {
	int y, x;
}yx;
queue<yx> q;
vector<yx> v;

int Bfs() {
	memcpy(visit, map, sizeof(map));
	
	int temp = 0; 
	while(!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<n && nx<n) {
				if(visit[ny][nx] == 0 && !virus[ny][nx]) {
					q.push({ny, nx});
					visit[ny][nx] = visit[y][x] + 1;
					temp = visit[ny][nx];
				}
			}
		}	
	}
		
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
				
			if(virus[i][j])
				continue;
					
			if(visit[i][j] == 0) {
				return -1;	
			}
		}
	}

	return temp;
}

void Virus(int depth, int index) {
	if(depth == m) {
					
		memset(virus, false, sizeof(virus));
		for(int i=0; i<v.size(); i++) {
			if(check[i]) {
				q.push({v[i].y, v[i].x});
				virus[v[i].y][v[i].x] = true;	
			}
		}
		
		int min_time = Bfs();
		if(min_time >= 0)
			ans = min(ans, min_time);
			
		return;
	}
	
	for(int i=index; i<v.size(); i++ ) {
		
		if(!check[i]) {
			check[i] = true;
			Virus(depth + 1, i);
			check[i] = false;
		}
		
	}
	
	
}

int main() {

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 2) {
				v.push_back({i, j});
				map[i][j] = 0;
			}

		}
	}
	
	Virus(0, 0);
	if(ans == 2147000000)
		cout << -1;
	else
		cout << ans; 

	return 0;
}
