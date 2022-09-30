#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 51

int map[MAX][MAX];
int check[MAX][MAX];

bool visit[14];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int n, m; 
int ans;

typedef struct {
	int y;
	int x;
}yx;

vector<yx> home;
vector<yx> chicken;

queue<yx> q;

int ChickenDist() {
	
	int total = 0;	
	for(int i=0; i<home.size(); i++) {
		int y = home[i].y;
		int x = home[i].x;

		total += check[y][x]; 
	}
	memset(check, false, sizeof(check));
	
	return total - home.size();
}

void Bfs() {
	
	while(!q.empty()) {
		int px = q.front().x;
		int py = q.front().y;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			
			int nx = px + dx[i];
			int ny = py + dy[i];
			
			if(nx>0 && ny>0 && nx<=n && ny<=n) {
				if(!check[ny][nx]) {

					check[ny][nx] = check[py][px] + 1;
					q.push({ny, nx}); 	
				}
			}	
		}	
	}	
}

void MinChicken() {
	
	int temp = 0;
	for(int i=0; i<chicken.size(); i++) {
		if(visit[i]) {
			q.push({chicken[i].y, chicken[i].x});
			check[chicken[i].y][chicken[i].x] = 1;
		} 
	}	
	Bfs();
	ans = min(ans, ChickenDist());
}

void SelectChicken(int depth, int index) { 
	
	if(depth == m) {
		
		MinChicken();			
		return;	
	}
	
	for(int i=index; i<chicken.size(); i++) {
		
		if(!visit[i]) {
			
			visit[i] = 1;
			SelectChicken(depth + 1, i);
			visit[i] = 0;	
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	

	/* input */
	cin >> n >> m;	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> map[i][j];
		
			if(map[i][j] == 1) {
				home.push_back({i,j});
			}
			else if(map[i][j] == 2) {
				chicken.push_back({i,j});
			}
			else;
			
		}
	}	

	ans = 2147000000;

	SelectChicken(0, 0);
	cout << ans;
		
	return 0;
}
