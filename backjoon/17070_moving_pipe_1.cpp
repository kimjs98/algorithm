#include <iostream>
#include <queue>

#define endl '\n'
#define MAX 17
using namespace std;

typedef struct {
	int y, x;
	int state;
}pos_t;

int map[MAX][MAX];
int check[MAX][MAX];

void Bfs(int num) {
	queue<pos_t> q;
	q.push({1, 2, 0});
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int state = q.front().state;

		q.pop();
		
		if(state == 0) {
		
			if((x + 1 <= num) && !map[y][x + 1]) {
					check[y][x + 1]++;
					q.push({y, x + 1, 0});
			}
			
			if((y + 1 <= num && x + 1 <= num)) {
				
				if(!(map[y][x + 1] || map[y + 1][x] || map[y + 1][x + 1])) {
					check[y + 1][x + 1]++;
					q.push({y + 1, x + 1, 2});					
				}

			}
		}
		else if(state == 1) {
			
			if((y + 1 <= num ) && !map[y + 1][x]) {
					check[y + 1][x]++;
					q.push({y + 1, x, 1});
			}
			
			if((y + 1 <= num && x + 1 <= num)) {
				if(!(map[y][x + 1] || map[y + 1][x] || map[y + 1][x + 1])) {
					check[y + 1][x + 1]++;
					q.push({y + 1, x + 1, 2});					
				}
			}
		}
		else {
			if((x + 1 <= num) && !map[y][x + 1]) {
					check[y][x + 1]++;
					q.push({y, x + 1, 0});
			}
			
			if((y + 1 <= num ) && !map[y + 1][x]) {
					check[y + 1][x]++;
					q.push({y + 1, x, 1});
			}
			
			if((y + 1 <= num && x + 1 <= num)) {
				if(!(map[y][x + 1] || map[y + 1][x] || map[y + 1][x + 1])) {
					check[y + 1][x + 1]++;
					q.push({y + 1, x + 1, 2});					
				}
			}
		}
	}
	
	cout << check[num][num];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<n+1; j++) {
			cin >> map[i][j];
		}
	}

	Bfs(n);
	
	return 0;
}
