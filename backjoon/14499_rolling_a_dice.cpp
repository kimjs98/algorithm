#include <cstring>
#include <iostream>

//#define DEBUG
#define MAX 20
#define bottom 6
#define top 1

using namespace std;

typedef struct {
	int y, x;
}pos_t;

int map[MAX][MAX];
int n, m, x, y, k;

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };

int dice_table[5][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 4, 2, 1, 6, 5, 3},
	{0, 3, 2, 6, 1, 5, 4},
	{0, 5, 1, 3, 4, 6, 2},
	{0, 2, 6, 3, 4, 1, 5}
};
int dice[7];
int temp[7];

pos_t MoveDice(pos_t pos, int dir);

void Input() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void Solve() {
	pos_t pos = { y, x };
	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;

		pos = MoveDice(pos, dir);
	}
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

pos_t MoveDice(pos_t pos, int dir) {
	int ny = pos.y + dy[dir];
	int nx = pos.x + dx[dir];

	if (ny >= 0 && nx >= 0 && ny < n && nx < m) {

		memcpy(temp, dice, sizeof(dice));
		for (int i = 1; i < 7; i++) {
			dice[i] = temp[dice_table[dir][i]];
		}

		if (!map[ny][nx])
			map[ny][nx] = dice[bottom];
		else {
			dice[bottom] = map[ny][nx];
			map[ny][nx] = 0;
		}

#ifdef DEBUG
		for (int i = 1; i < 7; i++) {
			cout << dice[i] << ' ';
		}
		cout << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
#endif
		cout << dice[top] << '\n';
	}
	else
		return pos;

	return { ny, nx };
}


