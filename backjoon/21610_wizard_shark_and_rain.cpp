#include <iostream>
#include <queue>

using namespace std;

//#define DEBUG 
#define MAX 51

typedef struct {
	int water;
	bool cloud;
}state_t;
state_t map[MAX][MAX];

typedef struct {
	int y, x;
}pos_t;
queue<pos_t> q_cloud;

int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int n, m;

void MoveCloud(int dir, int dist);
void WaterCopyMagic();
void RemoveCloud();

void Output() {
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			ans += map[i][j].water;
		}
	}
	cout << ans;
}

void Input() {

	cin >> n >> m;
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<n+1; j++) {
			cin >> map[i][j].water;
		}
	}

	/* make the first clouds */
	q_cloud.push({n, 1});
	q_cloud.push({n, 2});
	q_cloud.push({n-1, 1});
	q_cloud.push({n-1, 2});	
}

void Solve() {

	int d, s;
	for(int i=0; i<m; i++) {
		cin >> d >> s;

		MoveCloud(d, s);
		WaterCopyMagic();
		RemoveCloud();
	}

}

void Solution() {
	Input();
	Solve();
	Output();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution();

	return 0;
}

void MoveCloud(int dir, int dist) {

	while(!q_cloud.empty()) {

		if (dist > n)	dist = dist % n;

		int ny = q_cloud.front().y + dy[dir] * dist;
		int nx = q_cloud.front().x + dx[dir] * dist;

		q_cloud.pop();

		if (ny < 1)		ny = ny + n;
		else if (ny > n)	ny = ny - n;
		else;

		if (nx < 1)		nx = nx + n;
		else if (nx > n)	nx = nx - n;
		else;
	
		
		map[ny][nx].water++;
		map[ny][nx].cloud = true;
	}
}

void WaterCopyMagic() {
	
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<n+1; j++) {
			if(map[i][j].cloud) {
				
				for(int k=1; k<5; k++) {
					int ny = i + dy[k * 2];
					int nx = j + dx[k * 2];
					
					if(ny>0 && nx>0 && ny<=n && nx<=n) {
						if(map[ny][nx].water) {
							map[i][j].water++;
						}
					}
				}
			}
		}
	}
} 

void RemoveCloud() {
	
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<n+1; j++) {
			
			if(map[i][j].cloud) {
				map[i][j].cloud = false;
				continue;
			}

			if(map[i][j].water > 1) {

				map[i][j].water -= 2; 
				q_cloud.push({i, j});
#ifdef DEBUG
				cout << i << j << ' ';
#endif
			}
		}
	}

#ifdef DEBUG
	cout << '\n';
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << map[i][j].water << ' ';
		}
		cout << '\n';
	}
#endif
}
