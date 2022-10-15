#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int map[MAX][MAX];
int copy_map[MAX][MAX];

bool check[MAX][MAX];

int depth;
int n, k;

typedef struct{
	int y, x;	
}yx;


void Dfs(int y, int x, int cnt) {
	
	depth = max(depth, cnt);
	
	check[y][x] = true;
	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny>=0 && nx>=0 && ny<n && nx<n) {
	
			if(!check[ny][nx] && (copy_map[ny][nx] < copy_map[y][x]) ) {
				Dfs(ny, nx, cnt + 1);
			}
		}
	}
	check[y][x] = false;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_case;
	
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case) {

		cin >> n >> k;

		/* input */
		int max_height = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> map[i][j];		
				max_height = max(map[i][j], max_height);
			}
		}

		vector<yx> v;
		/* 꼭대기 위치 push */
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j] == max_height)
					v.push_back({i, j});
			}
		}

		depth = 2;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
			
				for(int c=1; c<=k; c++) {
					memcpy(copy_map, map, sizeof(map));
				
					copy_map[i][j] = map[i][j] - c;	// 지형 깎기  
		
					for(int m=0; m<v.size(); m++) {
					
						if(v[m].y == i && v[m].x == j)	continue;
						Dfs(v[m].y, v[m].x, 1);
					}
				}
			}
		}
		cout << "#" << test_case << ' ' << depth << '\n';
	}
	

	return 0;
}
