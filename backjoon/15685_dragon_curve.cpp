#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

typedef struct {
	int y, x;
}pos_t;

typedef struct {
	int y, x;
	int dir;
	int generation;
}curve_t;

int dy[] = {0, -1 ,0, 1};
int dx[] = {1, 0, -1, 0};

bool map[MAX][MAX];
int n;

void MakeDragonCurve(int r, int c, int d, int g) {
	
	queue<pos_t> q;
	map[r][c] = true;
	
	vector<int> v;
		
	int ny = r + dy[d];
	int nx = c + dx[d];
		
	map[ny][nx] = true;
	q.push({ny, nx});
	v.push_back(d);
	
	int y, x;
	int num = 1;

	if(num > g)	return;
	
	while(!q.empty()) {

		y = q.front().y;
		x = q.front().x;

		q.pop();

		int size = v.size();
		for(int i = size - 1; i >= 0; i--) {
			int dir = v[i] + 1;
			if(dir == 4) dir = 0;
			
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			map[ny][nx] = true;
			v.push_back(dir);
			
			y = ny;
			x = nx;
		}
		
		q.push({y, x});
		num++;
		
		if(num > g)	break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		MakeDragonCurve(y, x, d, g);
	}

	int ans = 0;
	for(int i=0; i<MAX - 1; i++) {
		for(int j=0; j<MAX - 1; j++) {
			if(map[i][j]) {
				if(map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
					ans++;
				}
			}
		}
	}
	cout << ans;	
	
	return 0;
}
