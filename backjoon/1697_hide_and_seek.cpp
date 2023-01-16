#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;

int location[MAX];
bool visit[MAX];

int n, k;

void Bfs(){
	int arr[] = { -1, 1, 2};
	queue<int> q;
	
	q.push(n);
	visit[n] = true;

	int x = n;
	while(x != k) {
		
		x = q.front();	
		q.pop();
		
		int arr[] = { -1, 1, x};
		for(int i=0; i<3; i++) {
			
			int nx = x + arr[i];
			if(nx > -1 && nx < MAX) {
				if(!visit[nx]) {
					q.push(nx);
					visit[nx] = true;
					
					location[nx] = location[x] + 1;  
				}
			}
		}
	}
	
	cout << location[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> k;
	Bfs();
		
	return 0;
}
