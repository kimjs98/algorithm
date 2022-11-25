#include <iostream>
#include <string>

#define DEBUG
#define MAX 50

using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

char map[MAX][MAX];
bool check[MAX][MAX];

typedef struct {
	int y, x;

}pos_t;
pos_t pos;

int n, m;
bool ans;

void Dfs(int y, int x, int depth) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (map[ny][nx] == map[y][x] && !check[ny][nx])
				Dfs(ny, nx, depth + 1);
			else if (depth >= 3) {
				if (pos.y == ny && pos.x == nx) {
					ans = true;
					return;
				}
			}
		}
	}
	check[y][x] = false;
}

void Input() {
	cin >> n >> m;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '\0';
		}
	}

}

void Solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (!check[i][j]) {
				pos = { i, j };
				Dfs(i, j, 0);
				check[i][j] = true;
			}
		}
	}

	if (ans)
		cout << "Yes";
	else
		cout << "No";

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

