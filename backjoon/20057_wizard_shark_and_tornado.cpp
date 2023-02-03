#include <iostream>
#include <vector>
#include <queue>

#define MAX 499

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int map[MAX][MAX];
int n, ans;

int y_table[4][10] = {
	{-1, -1, -1, 1, 1, 1, -2, 0, 2, 0},
	{-1, -1, 0, 0, 1, 1, 0, 2, 0, 1},
	{-1, -1, -1, 1, 1, 1, -2, 2, 0, 0},
	{-1, -1, 0, 0, 1, 1, -2, 0, 0, -1},

};

int x_table[4][10] = {
	{-1, 0, 1, -1, 0, 1, 0, -2, 0, -1},
	{-1, 1, -1, 1, -1, 1, -2, 0, 2, 0},
	{-1, 0, 1, -1, 0, 1, 0, 0, 2, 1},
	{-1, 1, -1, 1, -1, 1, 0, -2, 2, 0},
};

int sand_table[4][5][5] = {
	{{0, 0, 2, 0, 0},
	{0, 10, 7, 1, 0},
	{5, 0, 0, 0, 0},
	{0, 10, 7, 1, 0},
	{0, 0, 2, 0, 0}},
	
	{{0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{2, 7, 0, 7, 2},
	{0, 10, 0, 10, 0},
	{0, 0, 5, 0, 0}},
	
	{{0, 0, 2, 0, 0},
	{0, 1, 7, 10, 0},
	{0, 0, 0, 0, 5},
	{0, 1, 7, 10, 0},
	{0, 0, 2, 0, 0}},
	
	{{0, 0, 5, 0, 0},
	{0, 10, 0, 10, 0},
	{2, 7, 0, 7, 2},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0}}
};

void Input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}
}

void MoveSand(int y, int x, int dir) {	
	int total = map[y][x];
	map[y][x] = 0;

	int tmp;
	int total_tmp = 0;

	for(int i=0; i<9; i++) {
		int ny = y + y_table[dir][i];
		int nx = x + x_table[dir][i];

		int y_val = 2 + y_table[dir][i];
		int x_val = 2 + x_table[dir][i];

		tmp = total * sand_table[dir][y_val][x_val] / 100;
		total_tmp += tmp;
			
		if(ny>=0 && nx>=0 && ny<n && nx<n) {
			map[ny][nx] += tmp;
		}
		else {
			ans += tmp;
		}
	}
	
	int ny = y + y_table[dir][9];
	int nx = x + x_table[dir][9];
	if(ny>=0 && nx>=0 && ny<n && nx<n) {
			map[ny][nx] += total - total_tmp;
	}
	else {
		ans += total - total_tmp;
	}

}

void Move() {

	int y = n/2, x = n/2;
	int dir = 0, cnt = 0, dist_cnt = 0;
	int dist = 2;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			y += dy[dir];
			x += dx[dir];
			MoveSand(y, x, dir);

			cnt++;	
			if(dist / 2 == cnt) {
				dir = (dir + 1) % 4;
				cnt = 0;
			
				dist_cnt++;
				if(dist_cnt == 2) {
					dist_cnt = 0;
					dist += 2;
				}
			}
		}
	}
}

void Solution() {
	Input();
	Move();
	cout << ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	

	Solution();
	
	return 0;
}
