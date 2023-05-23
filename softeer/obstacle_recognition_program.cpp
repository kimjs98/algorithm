#include<iostream>
#include<queue>

#define MAX 25
#define endl '\n'
using namespace std;

typedef struct {
	int y, x;
}pos_t;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int n, cnt;
bool map[MAX][MAX];
bool check[MAX][MAX];

priority_queue<int, vector<int>, greater<int>> pq;

using namespace std;

void Bfs(int r, int c) {
	check[r][c] = true;
	
	queue<pos_t> q;
	q.push({r, c});
	
	int block_size = 1;
	while(!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			
			if(map[ny][nx] && !check[ny][nx]) {
				check[ny][nx] = true;
				
				q.push({ny, nx});
				block_size++;	
			}
		}
	}
	
	pq.push(block_size);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// input 
	cin >> n;
	string str;
	for(int i=0; i<n; i++) {
		cin >> str;
		for(int j=0; j<n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	// solution
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] && !check[i][j]) {
				Bfs(i, j);
				cnt++;				
			}
		}
	}

	// output
	cout << cnt << endl;
	while(!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}
