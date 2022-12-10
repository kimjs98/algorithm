#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG
#define MAX 20

using namespace std;

typedef struct {
	int y, x;

}pos_t;
queue<pos_t> q;
queue<pos_t> q_lainbow;
vector<pos_t> delete_v[MAX * MAX];

typedef struct {
	bool state;
	int group_size;
	int group_num;
	int lainbow_size;

}group_t;
queue<group_t> q_group;
vector<int> v_group;

bool check[MAX][MAX];
int map[MAX][MAX];
int temp[MAX][MAX];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int n, m, score;

/* step 1 ~ 2 */
void SearchGroup();
group_t MakeGroup(int r, int c, int num);
void SelectGroup(int block_size);

/* step 3 ~ 5 */
void Gravity();
void Move();

void Input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}
}

void Solve() {
	while (1) {
		SearchGroup();
		Gravity();
#ifdef DEBUG
		cout << "gravity 1" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == -1)		cout << "b" << ' ';
				else if (map[i][j] == -2)	cout << "x" << ' ';
				else						cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
#endif
		Move();
#ifdef DEBUG
		cout << "move" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == -1)		cout << "b" << ' ';
				else if (map[i][j] == -2)	cout << "x" << ' ';
				else						cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
#endif
		Gravity();

#ifdef DEBUG
		cout << "gravity 2" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == -1)		cout << "b" << ' ';
				else if (map[i][j] == -2)	cout << "x" << ' ';
				else						cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
#endif
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

void SearchGroup() {
	memset(check, false, sizeof(check));
	bool flag = false;
	int max_size = 0, max_lainbow_size = 0, group_num = 0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			
			if(map[i][j] == -1)	continue;

			if(!check[i][j] && map[i][j] > 0) {
				group_t temp_group = MakeGroup(i, j, ++group_num);

				/* 그룹으로 선정된 경우 */
				if(temp_group.state) {
					flag = true;

					/* 크기가 큰 그룹이 나타난 경우 갱신 */
					if (temp_group.group_size > max_size) {
						max_size = temp_group.group_size;

						while (!q_group.empty()) q_group.pop();
						q_group.push(temp_group);
					}
					else if (temp_group.group_size == max_size) {
						q_group.push(temp_group);

					}
					else;

				}
			}
		}
	
	}

	/* 그룹이 존재하지 않는경우 리턴 */
	if (!flag) {
		cout << score;
		exit(0);
	}
	else SelectGroup(max_size);

}

group_t MakeGroup(int r, int c, int num) {
	int block_cnt = 1;
	int lainbow_cnt = 0;
	int color = map[r][c];
	
	group_t group = { 0, };

	check[r][c] = true;
	q.push({ r, c });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {

				/* 검은 블록이 아니고, 그룹에 포함되지 않은 경우 */
				if (!check[ny][nx]) {
					if (map[ny][nx] == color) {
						check[ny][nx] = true;

						delete_v[num].push_back({ny, nx});

						block_cnt++;
						q.push({ ny, nx });
					}
					else if (map[ny][nx] == 0) {
						check[ny][nx] = true;
						q_lainbow.push({ ny, nx });

						delete_v[num].push_back({ ny, nx });

						lainbow_cnt++;
						q.push({ ny, nx });
					}
					else;

				}

			}
		}
	}
	
	while (!q_lainbow.empty()) {
		int y = q_lainbow.front().y;
		int x = q_lainbow.front().x;

		q_lainbow.pop();
		check[y][x] = false;
	}

	int block_size = block_cnt + lainbow_cnt;
	if (block_size > 1) {
		group = { true, block_size, num, lainbow_cnt };
		delete_v[num].push_back({ r, c });
	}

	return group;
}

void SelectGroup(int block_size) {

	int max_lainbow_size = 0;
	while(!q_group.empty()) {

		int group_num = q_group.front().group_num;
		int group_lainbow_size = q_group.front().lainbow_size;

		q_group.pop();
		
		if (group_lainbow_size > max_lainbow_size) {
			max_lainbow_size = group_lainbow_size;

			if (!v_group.empty()) v_group.clear();
			v_group.push_back(group_num);
		}
		else if (group_lainbow_size == max_lainbow_size) {
			v_group.push_back(group_num);
		}
		else;

	}

	int deleted_num = v_group.back();
	v_group.clear();

	/* 블록 삭제 */
	for (int i = 0; i < delete_v[deleted_num].size(); i++) {
		int y = delete_v[deleted_num][i].y;
		int x = delete_v[deleted_num][i].x;

		map[y][x] = -2;
	}

	for (int i = 0; i < (MAX * MAX); i++) {
		delete_v[i].clear();
	}
	
	score += block_size * block_size;

}

void Dfs(int y, int x, int depth) {
	if (y + 1 == n || map[y + 1][x] > -2) {
		swap(map[y][x], map[y - depth][x]);
		return;
	}
	else
		Dfs(y + 1, x, depth + 1);
}

void Gravity() {
	for(int i=n-2; i>-1; i--) {
		for(int j=0; j<n; j++) {
			if (map[i][j] == -1 || map[i + 1][j] > -1)	continue;

			Dfs(i, j, 0);	
		}
	}
}

void Move() {
	memcpy(temp, map, sizeof(map));

	int cnt = n-1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[j][cnt];
		}
		cnt--;
	}
}