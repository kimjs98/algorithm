#include <algorithm>
#include <cstring>
#include <math.h>
#include <iostream>
#include <queue>

#define endl '\n'
#define MAX 65
using namespace std;

typedef struct {
	int y, x;
}pos_t;

int arr[] = {1, 2, 4, 8, 16, 32, 64};
int level[1001];

int n, q, num;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int map[MAX][MAX];
int tmp[MAX][MAX];
bool check[MAX][MAX];

void Firestorm(int section);
void CheckIce();
int CheckBigIce(int r, int c);

void Input() {

	cin >> n >> q;
	num = pow(2, n);
	for(int i=1; i<=num; i++) {
		for(int j=1; j<=num; j++) {
			cin >> map[i][j];
		}
	}

	for(int i=1; i<=q; i++) {
		cin >> level[i];
	}
}

void Solve() {

	int ans_sum = 0;
	int ans_maxcnt = 0;
	for(int i=1; i<=q; i++) {
		//cout << "q : " << i << " level : " << arr[level[i]] << endl;
		
		Firestorm(arr[level[i]]);
		CheckIce();
	}

	int sum = 0;
	int maxcnt = 0;
	for(int i=1; i<=num; i++) {
		for(int j=1; j<=num; j++) {
			if(map[i][j]) {
				sum += map[i][j];
				
				if(!check[i][j]) {
					int ret = CheckBigIce(i, j);
					maxcnt = max(ret, maxcnt);
				}			
			}
		}
	}
		
	cout << sum << endl;
	cout << maxcnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Input();
	Solve();
	return 0;	
}

void Lotate(int y, int x, int section) {
	
	int r = y;
	int c = x;
	
	for(int i=x; i<x + section; i++) {
		
		c = x;
		for(int j=y + section - 1; j>=y; j--) {
			tmp[r][c] = map[j][i];
			c++;
		}
		r++;
	}
}

void Firestorm(int section) {
	// 시작 위치(y, x)를 입력받아 section 크기만큼 배열을 돌리는 함수 구현.
	int idx = num / section;
	
	int y, x;
	y = x = 1;
	for(int i=1; i<=idx; i++) {
		
		x = 1;
		for(int j=1; j<=idx; j++) {
			Lotate(y, x, section);
			x += section;
		}
		y += section;
	}

}

void CheckIce() {
	vector<pos_t> v;
	
	for(int i=1; i<=num; i++) {
		for(int j=1; j<=num; j++) {
			if(!tmp[i][j]) continue;
			
			int ice_cnt = 0;
			for(int k=0; k<4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				if(ny>0 && nx>0 && ny<=num && nx<=num) {
					if(tmp[ny][nx])	ice_cnt++;
				}
			}
			
			if(ice_cnt < 3)	v.push_back({i, j});
		}
	}

	for(int i=0; i<v.size(); i++) {
		int y = v[i].y;
		int x = v[i].x;
		
		tmp[y][x]--;
	}
	
	memcpy(map, tmp, sizeof(map));
}

int CheckBigIce(int r, int c) {
	check[r][c] = true;
	queue<pos_t> q;
	q.push({r, c});
	
	int cnt = 1;
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		
		q.pop();
		
		for(int k=0; k<4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			
			if(ny>0 && nx>0 && ny<=num && nx<=num) {
				if(tmp[ny][nx] && !check[ny][nx]) {
					
					q.push({ny, nx});
					check[ny][nx] = true;
					cnt++;
				}
			}
		}
	}
	
	return cnt;
}
