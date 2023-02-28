#include <algorithm>
#include <iostream>
#include <deque>

#define INF 2147000000
#define MAX 301
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; 

int n, m, x1, y1, x2, y2;
int map[MAX][MAX];
int check[MAX][MAX];

typedef struct {
	int y, x;
}pos_t;

/*
	solution : 0-1 bfs algorithm
*/

void Bfs(int y1, int x1, int y2, int x2) {
	fill(&check[0][0], &check[MAX - 1][MAX], INF);
	
	deque<pos_t> dq;
	dq.push_front({y1, x1});
	
	check[y1][x1] = 0;
	map[y1][x1] = 0;
	map[y2][x2] = 1;

	while(!dq.empty()) {
		int y = dq.front().y;
		int x = dq.front().x;
		dq.pop_front();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny>0 && nx>0 && ny<=n && nx<=m) {
				if(check[y][x] + map[ny][nx] < check[ny][nx]) {
					check[ny][nx] = check[y][x] + map[ny][nx];
							
					if(map[ny][nx])	dq.push_back({ny, nx});
					else			dq.push_front({ny, nx});
				}
			}
		}
	}

/*
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {
			cout << check[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
*/

	cout << check[y2][x2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	
	string str;
	for(int i=0; i<n; i++) {
		cin >> str;
		for(int j=0; j<m; j++) {
			map[i + 1][j + 1] = str[j] - '0';
		}
	}
	Bfs(y1, x1, y2, x2);

}
