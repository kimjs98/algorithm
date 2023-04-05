/*

time limit : 0.3s
n * n 격자. 가장 처음 모든 칸에 양분은 5

m개의 나무를 구매해 땅에 심음. 같은 위치에 여러 개의 나무가 심어져 있을 수 있음.

나무는 사계절에 아래 과정 반복.

봄 : 자신의 나이만큼 자신이 존재하는 칸의 양분을 먹고, 나이가 1 증가. 
하나의 칸에 여러 나무가 있으면, 나이가 어린 나무부터 양분 섭취.
양분이 부족해 나이만큼 먹지 못하면 즉시 사망.

여름 : 봄에 죽은 나무가 양분으로 변화. 죽은 나무를 2로 나눈 값이 해당 위치에 추가

가을 : 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무 생성.

겨울 : 모든 땅에 양분 추가(입력으로 주어짐) 

-> k년 이후 땅에 살아있는 나무의 개수 출력.

*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 11
using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

typedef struct {
	int y, x;
	int age;
}wood_t;

int n, m, k;

int a[MAX][MAX];
int map[MAX][MAX];
int tmp[MAX][MAX];

vector<int> v[MAX][MAX];
// 위치정보가 필요없으므로 2차원 벡터로 선언해 age만 비교값으로 사용

vector<wood_t> dead_v; 

void Spring();	
void Summer();
void Fall();
void Winter();

void Input() {
	cin >> n >> m >> k;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> a[i][j];
			
			map[i][j] = 5;
		}
	}
	
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x][y].push_back(z);
	}	
}

void Solve() {
	while(k--) {
		Spring();
		//Summer();
		Fall();
		Winter();
	}
	
	int ans = 0;
	for(int r=1; r<n+1; r++) {
		for(int c=1; c<n+1; c++) {
			ans += v[r][c].size(); 
		}
	}
	
	cout << ans;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}

void Spring() {
	
	for(int r=1; r<n+1; r++) {
		for(int c=1; c<n+1; c++) {
			sort(v[r][c].begin(), v[r][c].end());
			
			for(int i=0; i<v[r][c].size(); i++) {
				
				if(v[r][c][i] > map[r][c]) {
					//dead_v.push_back({r, c, v[r][c][i]});
					tmp[r][c] += v[r][c][i] / 2;
					
					v[r][c].erase(v[r][c].begin() + i);
					i--;
				}
				else {
					map[r][c] -= v[r][c][i];
					v[r][c][i]++;
				}
				
			}
		}
	}
	
}

void Summer() {
	for(int i=0; i<dead_v.size(); i++) {
		int y = dead_v[i].y;
		int x = dead_v[i].x;
		map[y][x] += dead_v[i].age / 2;
	}
	
	dead_v.clear();
}

void Fall() {
	for(int r=1; r<n+1; r++) {
		for(int c=1; c<n+1; c++) {		
			for(int i=0; i<v[r][c].size(); i++) {
				if(v[r][c][i] % 5 == 0 && v[r][c][i] >= 5) {
					
					for(int j=0; j<8; j++) {
						int ny = r + dy[j];
						int nx = c + dx[j];
						if(ny > 0 && nx > 0 && ny <= n && nx <= n) {
							v[ny][nx].push_back(1);	
						}
					}
				}
			}
		}
	}
}

void Winter() {
	for(int r=1; r<n+1; r++) {
		for(int c=1; c<n+1; c++) {
			map[r][c] += a[r][c] + tmp[r][c];
			tmp[r][c] = 0; 
		}
	}
}
