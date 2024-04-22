#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// time limit : 2s / 512 MB / n, m <= 8
using namespace std;

typedef struct {
	int y, x;
}pos_t;

typedef struct {
	int y, x, num;
}cctv_t;
vector<cctv_t> v;

const int MAX = 8;
const int WALL = 6;

int map[MAX][MAX];
bool vis[MAX][MAX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int arr[MAX]; 
int n, m, ans, wall_cnt;

bool oob(int a, int b) {
	return a < 0 or b < 0 or a >= n or b >= m;
}

int search(int y, int x, int dir) {
	int cnt = 0;
	
	while(1) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		y = ny; 
		x = nx;		
		
		if(oob(ny, nx) || map[ny][nx] == 6) return cnt;	
		if(map[ny][nx] || vis[ny][nx]) continue;
		
		cnt++;
		vis[ny][nx] = true;
	}
}

int Simulation(int y, int x, int num, int dir) {
	// pos, cctv num, dir
	int sum = 0;

	if(num == 1) {
		sum = search(y, x, dir);
	}
	else if(num == 2) {
		dir /= 2;
		
		sum += search(y, x, dir);
		sum += search(y, x, dir + 2);
	}
	else if(num == 3) {
		sum += search(y, x, dir);
		
		if(dir == 3) dir = -1;
		sum += search(y, x, dir + 1);
	}
	else if(num == 4) {
		for(int i=0; i<4; ++i) {
			if(i == dir) continue;
			sum += search(y, x, i);
		}
	}
	else {
		for(int i=0; i<4; ++i) {
			sum += search(y, x, i);
		}
	}
	
	return sum;
}

void BackTracking(int cnt){
    if(cnt == v.size()){
		memset(vis, false, sizeof(vis));
		int sum = 0;
        for(int i=0; i<v.size(); ++i) {
        	//cout << arr[i] << ' ';
			sum += Simulation(v[i].y, v[i].x, v[i].num, arr[i]);		
		}
		//cout <<'\n';
		int tot = n*m - sum - wall_cnt - v.size();
		//cout << tot << '\n';
		ans = min(ans, tot);
		
        return;
    }
    
    for(int i = 0; i < 4; i++){
        arr[cnt] = i;
        BackTracking(cnt+1);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i=0; i<n; ++i) {		
		for(int j=0; j<m; ++j) {
			cin >> map[i][j];
			if(!map[i][j]) continue;
			if(map[i][j] == 6) {
				wall_cnt++;
				continue;
			}

			v.push_back({i, j, map[i][j]});
		}
	}

	ans = 64;
	BackTracking(0);
	cout << ans;
	
	return 0;
}
