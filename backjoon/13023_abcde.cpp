#include <iostream>
#include <vector>

using namespace std;
int ans;
int n, m;  // n : node, m : edge

bool visit[2001];
vector<int> arr[2001];

void Dfs(int x) {
	
	visit[x] = true;
	for (int i=0; i<arr[x].size(); i++) {
		int next = arr[x][i];
		if (visit[next] == false ) {
			Dfs(next);
		}
		
	}
		
}

int main() {
	
	cin >> n >> m;
	for( int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	Dfs(0);

#if 0
	for(int i=0; i<n; i++) {
		
		for (int a: arr[i]) {
			cout << a << ' ';
		}
		cout << '\n';
	}
#endif 	
	return 0;
}


