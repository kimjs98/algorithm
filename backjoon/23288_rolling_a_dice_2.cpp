#include <cstring>
#include <iostream>
#include <queue>

//#define DEBUG
#define MAX 21
#define bottom 6
#define top 1

using namespace std;

typedef struct {
	int y, x;
}pos_t;

typedef struct {
	pos_t pos;
	int dir;
}dice_t;

int map[MAX][MAX];
int n, m, k, ans;

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };
	
int dice_table[5][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 4, 2, 1, 6, 5, 3},
	{0, 3, 2, 6, 1, 5, 4},
	{0, 5, 1, 3, 4, 6, 2},
	{0, 2, 6, 3, 4, 1, 5}
};

int reverse[] = {0, 2, 1, 4, 3 };
int rotate1[] = {0, 4, 3, 1, 2};
int rotate2[] = {0, 3, 4, 2, 1};

int dice_state[7] = {0, 1, 2, 3, 4, 5, 6}; 
int temp[7];

dice_t MoveDice(dice_t dice);
void CalScore(int y, int x);

void Input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

void Solve() {
	dice_t dice = {{1, 1}, 1};
	for (int i = 0; i < k; i++) {
#ifdef DEBUG		
		cout << "dice pos : " << dice.pos.y << dice.pos.x << " dice dir : " << dice.dir << '\n';
#endif
		dice = MoveDice(dice);	
	}
	cout << ans;
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution();

	return 0;
}

void RollingDice(int dir) {
	memcpy(temp, dice_state, sizeof(dice_state));
	for(int i=1; i<7; i++) {
		dice_state[i] = temp[dice_table[dir][i]];
	}		
}

dice_t MoveDice(dice_t dice){
	
	int dir = dice.dir;
	int ny = dice.pos.y + dy[dir];
	int nx = dice.pos.x + dx[dir];

	if(ny>0 && nx>0 && ny<=n && nx<=m) {

		RollingDice(dir);	
		CalScore(ny, nx);
	}
	else {
		/* reverse a direction */
		dir = reverse[dir];

		ny = dice.pos.y + dy[dir];
		nx = dice.pos.x + dx[dir];

		RollingDice(dir);		
		CalScore(ny, nx);	
	}

	if(dice_state[bottom] > map[ny][nx])		dir = rotate1[dir];
	else if(dice_state[bottom] < map[ny][nx]) 	dir = rotate2[dir];
	else;
	
	dice = {{ny, nx}, dir};
	return dice;
}

void CalScore(int r, int c) {
	
	bool check[MAX][MAX] = {0, };	
	int score = map[r][c];
	check[r][c] = true;
	int cnt = 1;

	queue<pos_t> q;
	q.push({r, c});

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for(int i=1; i<5; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny>0 && nx>0 && ny<=n && nx<=m) {

				if(!check[ny][nx] && map[ny][nx] == score) {
					q.push({ny, nx});
					check[ny][nx] = true;
					cnt++;
				}
			}
		}
	}	
	ans += score * cnt;
#ifdef DEBUG
	cout << "score : " << score << " cnt : "<< cnt << '\n';
	cout << "ans : " << ans << '\n';
#endif
}

