#include <iostream>
#include <queue>

//#define DEBUG
#define MAX 100001
using namespace std;

typedef struct {
	int location;
	int cnt;
}pos_t;

pos_t pos[MAX];
int n, k;

void Bfs(){
	int arr[] = { -1, 1, 2};
	queue<int> q;
	
	q.push(n);
	pos[n].location = 1;

	int x = n;
	while(x != k) {
		
		x = q.front();	
		q.pop();
		
		int arr[] = { -1, 1, x};
		for(int i=0; i<3; i++) {
			int nx = x + arr[i];
			if(nx > -1 && nx < MAX) {
				if(!pos[nx].location) {
					q.push(nx);
					
					pos[nx].location = pos[x].location + 1;
					pos[nx].cnt++;
				}
				else {
					int tmp = pos[x].location + 1;
					if(tmp == pos[nx].location) {
						q.push(nx);
						pos[nx].cnt++;
					}
				}
			}
		}
	}
	cout << pos[k].location - 1 << '\n' << pos[k].cnt;
	
#ifdef DEBUG
	for(int i=0; i<=k; i++) {
		cout << pos[i].location << ' ';
	}
	cout << '\n';

	for(int i=0; i<=k; i++) {
		cout << pos[i].cnt << ' ';
	}
	cout << '\n';
#endif

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> k;
	
	if(n > k)		cout << n - k << '\n' << 1;
	else if(n == k)	cout << 0 << '\n' << 1;
	else 			Bfs();
	
	return 0;
}
