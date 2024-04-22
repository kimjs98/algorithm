#include <cstring>
#include <iostream>
#include <queue>

//#define DEBUG
using namespace std;

typedef struct {
	int y, x;
}pos_t;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

char map[13][6];
bool check[13][6];
bool state;
int chain;

void Down() {
	for(int i=0; i<6; ++i) {
		for(int j=10; j>=0; --j) {
			int layer = j;
			while(map[layer + 1][i] == '.') {
				map[layer + 1][i] = map[layer][i];
				map[layer][i] = '.';
				layer++;
			}
		}
	}
}

void Bfs(int r, int c) {
	check[r][c] = true;
	if(map[r][c] == '.') return;
	
	queue<pos_t> q, q2;
	q.push({r, c});
	q2.push({r, c});
	
	int col = map[r][c];

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
			if(check[ny][nx]) continue;
			
			if(map[ny][nx] == col) {

				q.push({ny, nx});
				q2.push({ny, nx});
				check[ny][nx] = true;				
			}
		}
		
	}
	
	if(q2.size() > 3) {

		while(!q2.empty()) {
			int y = q2.front().y;
			int x = q2.front().x;
			q2.pop();
		
			map[y][x] = '.';
		}
		
		state = true;
	}
}

void Simulation() {

	for(int i=11; i>=0; --i) {
		for(int j=0; j<6; ++j) {
			
			if(check[i][j]) continue;
			Bfs(i, j);
		}
	}
	
	if(state) {
		chain++;
		
		Down();
		memset(check, false, sizeof(check));
		state = false;
		
		Simulation();
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i=0; i<12; ++i)
		for(int j=0; j<6; ++j) cin >> map[i][j];

	for(int i=0; i<6; ++i) map[12][i] = 0;

	Simulation();


#ifdef DEBUG
	for(int i=0; i<12; ++i) {
		for(int j=0; j<6; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

	cout << chain;
	return 0;
}
