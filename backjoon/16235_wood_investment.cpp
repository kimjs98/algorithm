/*

time limit : 0.3s
n * n ����. ���� ó�� ��� ĭ�� ����� 5

m���� ������ ������ ���� ����. ���� ��ġ�� ���� ���� ������ �ɾ��� ���� �� ����.

������ ������� �Ʒ� ���� �ݺ�.

�� : �ڽ��� ���̸�ŭ �ڽ��� �����ϴ� ĭ�� ����� �԰�, ���̰� 1 ����. 
�ϳ��� ĭ�� ���� ������ ������, ���̰� � �������� ��� ����.
����� ������ ���̸�ŭ ���� ���ϸ� ��� ���.

���� : ���� ���� ������ ������� ��ȭ. ���� ������ 2�� ���� ���� �ش� ��ġ�� �߰�

���� : ���̰� 5�� ����� ������ ����. ������ 8�� ĭ�� ���̰� 1�� ���� ����.

�ܿ� : ��� ���� ��� �߰�(�Է����� �־���) 

-> k�� ���� ���� ����ִ� ������ ���� ���.

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
// ��ġ������ �ʿ�����Ƿ� 2���� ���ͷ� ������ age�� �񱳰����� ���

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
