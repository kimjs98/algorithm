#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>

#define MAX 101
#define INF 2147000000
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; 

typedef struct {
	int y, x;
}pos_t;

bool map[MAX][MAX];
int check[MAX][MAX];

/*
	(1, 1) to (n, m) 로 이동하기 위해 부수어야 하는 벽의 최소 개수 출력
	
	solution : 0-1 bfs algorithm
*/

void Bfs(int r, int c) {
	fill(&check[0][0], &check[MAX - 1][MAX], INF);

	deque<pos_t> dq;

	dq.push_front({1, 1});
	check[1][1] = 0;
	
	while(!dq.empty()) {
		int y = dq.front().y;
		int x = dq.front().x;
		dq.pop_front();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny>0 && nx>0 && ny<=r && nx<=c) {
				if(check[y][x] + map[ny][nx] < check[ny][nx]) {
					check[ny][nx] = check[y][x] + map[ny][nx];
							
					if(map[ny][nx])	dq.push_back({ny, nx});
					else			dq.push_front({ny, nx});
				}
			}
		}
	}
	cout << check[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> m >> n;
	
	string str;
	for(int i=0; i<n; i++) {
		cin >> str;
		for(int j=0; j<m; j++) {
			map[i+1][j+1] = str[j] - '0';
		}
	}
	Bfs(n, m);

	return 0;
}
