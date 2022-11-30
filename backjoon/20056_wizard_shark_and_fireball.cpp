#include <cstring>
#include <iostream>
#include <queue>

//#define DEBUG 
#define MAX 51

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct {
	int y, x;
}pos_t;

typedef struct {
	pos_t pos;
	int mass;
	int speed;
	int dir;
}state_t;

typedef struct {
	int cnt;
	int mass;
	int speed;
	int dir;
	bool flag;

}fireball_t;

fireball_t map[MAX][MAX];

queue<state_t> q;
int n, m, k;

void MoveFireball();
void FireballEvent();
void DivideFireball(pos_t pos, int mass, int speed, bool flag);

void Input() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int idx0, idx1, idx2, idx3, idx4;
		cin >> idx0 >> idx1 >> idx2 >> idx3 >> idx4;
		
		q.push({ {idx0, idx1}, idx2, idx3, idx4 });
	}
}

void Solve() {
	while (k--) {
		MoveFireball();
		FireballEvent();
	}

	int mass = 0;
	while (!q.empty()) {
		mass += q.front().mass;
		q.pop();
	}
	cout << mass;

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

void MoveFireball() {

	while (!q.empty()) {
	
		int speed = q.front().speed;
		if (speed > n)	speed = speed % n;

		int ny = q.front().pos.y + dy[q.front().dir] * speed;
		int nx = q.front().pos.x + dx[q.front().dir] * speed;

		if (ny < 1)		ny = ny + n;
		else if (ny > n)	ny = ny - n;
		else;

		if (nx < 1)		nx = nx + n;
		else if (nx > n)	nx = nx - n;
		else;

		map[ny][nx].cnt++;
		map[ny][nx].mass += q.front().mass;
		map[ny][nx].speed += q.front().speed;

		if (map[ny][nx].cnt > 1) {
			if ((map[ny][nx].dir % 2) != (q.front().dir % 2))	map[ny][nx].flag = true;

			map[ny][nx].dir = q.front().dir;
		}
		else
			map[ny][nx].dir = q.front().dir;

		q.pop();
	}


}

void FireballEvent() {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (!map[i][j].cnt)	continue;

			if (map[i][j].cnt == 1) {
				q.push({ {i, j}, map[i][j].mass, map[i][j].speed, map[i][j].dir });
			}
			else {
				int mass = map[i][j].mass / 5;
				int speed = map[i][j].speed / map[i][j].cnt;

				if(mass)
					DivideFireball({ i, j }, mass, speed, map[i][j].flag);
			}
		}
	}

	memset(map, false, sizeof(map));
}

void DivideFireball(pos_t pos, int mass, int speed, bool flag) {
	for (int i = 0; i < 4; i++)
		q.push({ pos, mass, speed, i * 2 + flag });
}