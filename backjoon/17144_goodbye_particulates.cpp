#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX	50

typedef struct {
	int y, x;
}yx;
queue<yx> q;
vector<yx> v;

int map[MAX][MAX];
int temp[MAX][MAX];

int r, c, t;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

void Diffusion() {
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if((ny>=0 && nx>=0 && ny<r && nx<c) && (map[ny][nx] != -1)) {
				
				int diffusion_value = map[y][x]/5;	
		
				temp[y][x] -= diffusion_value;
				temp[ny][nx] += diffusion_value;
			}
		}		
	}		
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {			
			map[i][j] += temp[i][j];
			temp[i][j] = 0;
	
		}
	}
}

void AirCleanUp(int y, int x, int temp, int level) {

	int next = map[y][x];
	map[y][x] = temp; 

	if(level == 0) {
		if(x + 1 == c)
			AirCleanUp(y - 1, x, next, level + 1);
		else
			AirCleanUp(y, x + 1, next, level);		
	}
	else if(level == 1) {
		if(y == 0)
			AirCleanUp(y, x - 1, next, level + 1);
		else
			AirCleanUp(y - 1, x, next, level);
	}
	else if(level == 2) {
		if(x == 0)
			AirCleanUp(y + 1, x, next, level + 1);
		else
			AirCleanUp(y, x - 1, next, level);
	}
	else {
		if( map[y + 1][x] == -1) {
			
			return;	
		}
		else
			AirCleanUp(y + 1, x, next, level);
	}
	
	
}

void AirCleanDown(int y, int x, int temp, int level) {
	int next = map[y][x];
	map[y][x] = temp;

	if(level == 0) {
		if(x + 1 == c)
			AirCleanDown(y + 1, x, next, level + 1);
		else
			AirCleanDown(y, x + 1, next, level);		
	}
	else if(level == 1) {
		if(y == r - 1)
			AirCleanDown(y, x - 1, next, level + 1);
		else
			AirCleanDown(y + 1, x, next, level);
	}
	else if(level == 2) {
		if(x == 0)
			AirCleanDown(y - 1, x, next, level + 1);
		else
			AirCleanDown(y, x - 1, next, level);
	}
	else {
		if( map[y - 1][x] == -1) {
			return;	
		}
		else
			AirCleanDown(y - 1, x, next, level);
	}	
}

int main() {
	
	cin >> r >> c >> t;
	
	bool flag = false;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> map[i][j];
			
			if(map[i][j] >= 5)	q.push({i, j});
			if(map[i][j] == -1)	 v.push_back({i, j});
		}
	}
	
	int temp = 0;
	for (int i=0; i<t; i++) {	
		Diffusion();

		temp = map[v[0].y][v[0].x + 1];
		map[v[0].y][v[0].x + 1] = 0;
		AirCleanUp(v[0].y, v[0].x + 2, temp, 0);

		temp = map[v[1].y][v[1].x + 1];
		map[v[1].y][v[1].x + 1] = 0;
		AirCleanDown(v[1].y, v[1].x + 2, temp, 0);		
		
		
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {	
				if(map[i][j] >=5)
					q.push({i, j});
			}
		}
	}

	int ans = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {	
			if( map[i][j] <= 0) continue;
			ans += map[i][j];
		}
	}
	cout << ans;
	
	return 0;
}

