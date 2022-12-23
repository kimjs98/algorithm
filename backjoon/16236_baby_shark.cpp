#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG
#define MAX 20

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int map[MAX][MAX];
int n, m, cnt, size;

typedef struct {
	int y, x;
}pos_t;
vector<pos_t> v_fish;

typedef struct {
	pos_t pos;
	int size;
	int fish;
}shark_t;
shark_t shark;

bool compare(const pos_t &a, const pos_t &b) {
	if(a.y == b.y) {
		return a.x < b.x;
	}
	else
		return a.y < b.y;
}

void Move();
void EatFish();
 
void Input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) {
				shark = {{i, j}, 2, 0};
				map[i][j] = 0;	
			}	
		}
	} 	
}

void Solve() {
	while(1) {
		Move();
		EatFish();	
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

void Move() {
	int check[MAX][MAX] = {0, };
	check[shark.pos.y][shark.pos.x] = true;
	
	queue<pos_t> q;
	q.push({shark.pos.y, shark.pos.x});
	
	int min = 0;
	bool flag = false;
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if((ny>=0 && nx>=0 && ny<n && nx<n) && !check[ny][nx]) {
				
				if(map[ny][nx] > 0 && map[ny][nx] < shark.size) {
					
					check[ny][nx] = check[y][x] + 1;	// 방문 체크 
					
					if(!flag) {
						flag = true; 
						v_fish.push_back({ny, nx});
						
						min = check[y][x];					
					}
					else {
						if(check[y][x] == min)
							v_fish.push_back({ny, nx});
					}

				}
				else if(map[ny][nx] == 0 || map[ny][nx] == shark.size) {
					
					q.push({ny, nx});
					check[ny][nx] = check[y][x] + 1;
				}
				else;
			}
		}
	}
	
	cnt += min;
	if(!flag) {
		cout << cnt;
		exit(0); 
	}
}

void EatFish() {
	if(v_fish.size() > 1)
		sort(v_fish.begin(), v_fish.end(), compare);

	int y = v_fish[0].y;
	int x = v_fish[0].x;
	int size = map[y][x];

	map[y][x] = 0;
	shark.pos = {y, x};
	shark.fish++;
	if(shark.fish == shark.size) {
		shark.fish = 0;
		shark.size++;
	}

#ifdef DEBUG
	cout << "eatfish" << '\n';
	for(int i=0; i<v_fish.size(); i++) {
		cout << v_fish[i].y << v_fish[i].x << ' ';
	}
	cout << '\n';
	
	cout << "shark pos : " << shark.pos.y << shark.pos.x << '\n';
 	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
#endif

	v_fish.clear();
}






