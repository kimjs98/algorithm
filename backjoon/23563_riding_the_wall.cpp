#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

#define MAX 501
#define INF 2147000000

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; 

int h, w;

typedef struct {
	int y, x;
}pos_t;

int map[MAX][MAX];
int check[MAX][MAX];

void Bfs(pos_t start, pos_t end) {
	fill(&check[0][0], &check[MAX - 1][MAX], INF);
	deque<pos_t> dq;
	
	dq.push_front({start.y, start.x});
	check[start.y][start.x] = 0;

	while(!dq.empty()) {
		int y = dq.front().y;
		int x = dq.front().x;
		dq.pop_front();
		
		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i]; 
			
			if(ny>0 && nx>0 && ny<=h && nx<=w) {
				if(map[ny][nx] > -1) {
					
					int cost = 1;
					if(map[ny][nx] == 2 && map[y][x] == 2)	cost = 0;	
					
					if(check[y][x] + cost < check[ny][nx]) {
						check[ny][nx] = check[y][x] + cost;
						
						if(map[ny][nx])		dq.push_back({ny, nx});
						else				dq.push_front({ny, nx});
					}					
				}

			}
		}
	}
	
	cout << check[end.y][end.x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> h >> w;
	
	string str;
	pos_t start, end;
	vector<pos_t> v;
	
	for(int i=0; i<h; i++) {
		cin >> str;
		for(int j=0; j<w; j++) {
			if(str[j] == '.')		map[i + 1][j + 1] = 1;
			else if(str[j] == 'S')	start = {i + 1, j + 1};
			else if(str[j] == 'E')	{
				map[i + 1][j + 1] = 1;
				end = {i + 1, j + 1};	
			}
			else {
				map[i + 1][j + 1] = -1;
				v.push_back({i + 1, j + 1});
			}
		}
	}
	
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<4; j++) {
			int ny = v[i].y + dy[j];
			int nx = v[i].x + dx[j];
			
			if(ny>0 && nx>0 && ny<=h && nx<=w) {
				if(map[ny][nx] == -1)	continue;
				
				map[ny][nx] = 2;
			}
		}
	}
	
	Bfs(start, end);

	return 0;
}
