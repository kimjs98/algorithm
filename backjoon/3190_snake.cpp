#include <iostream>
#include <deque>

#define endl '\n'
#define MAX 101
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

typedef struct {
	int y, x;
}snake_t;

bool map[MAX][MAX];
bool snake[MAX][MAX];
char turn[10001];

int n, k, l;

void Move() {
		
	deque<snake_t> dq;
	dq.push_front({1, 1});
	
	snake[1][1] = true;
	int dir = 1;
	int time = 0;
	
	while(1) {	
		time++;					
		
		int ny = dq.front().y + dy[dir];
		int nx = dq.front().x + dx[dir];
		
		if(ny>0 && nx>0 && ny<=n && nx<=n) {
			if(snake[ny][nx]) break;
			
			snake[ny][nx] = true;
			dq.push_front({ny, nx});
			
			if(map[ny][nx]) map[ny][nx] = false;
			else {
				int by = dq.back().y;
				int bx = dq.back().x;

				snake[by][bx] = false;
				dq.pop_back();
			}
	
		}
		else break;
		
		if(turn[time] == 'D') {
			if(dir == 3) dir = 0;
			else		 dir++;
		}
		else if(turn[time] == 'L') {
			if(dir == 0) dir = 3;
			else		 dir--;
		}
		else;

	}
	
	cout << time;
}

void Input() {
	
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		int r, c;
		cin >> r >> c;

		map[r][c] = true;			
	}

	cin >> l;
	for(int i=0; i<l; i++) {
		int x;
		char c;
		cin >> x >> c;
		turn[x] = c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	Input();
	Move();

	return 0;
}
