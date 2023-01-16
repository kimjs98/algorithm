#include <iostream>
#include <queue>

#define MAX 1000001
using namespace std;

int visit[MAX];

int f, s, g, u, d;

void Bfs() {
	queue<int> q;
	q.push(s);
	visit[s] = 1;
	
	while(!q.empty()) {
		
		int y = q.front();
		q.pop();
		
		if(y == g) {
			cout << visit[y] - 1;
			exit(0);
		}
		
		int arr[] = {u, -d};
		for(int i = 0; i < 2; i++) {
			int ny = y + arr[i];
			if(ny > 0 && ny <= f) {
				if(!visit[ny]) {
					q.push(ny);
					visit[ny] = visit[y] + 1;	
				}
			}
		}
	}
	
	cout << "use the stairs";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> f >> s >> g >> u >> d;
	Bfs();
	
	return 0;
}
