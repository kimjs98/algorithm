#include <iostream>
#include <vector>

using namespace std;
int ans;
int n, m;  // n : node, m : edge

bool visit[2000];
vector<int> arr[2000];

void Dfs(int index, int depth) {
	
	if (depth == 4) {
		ans = 1;
		return;
	}
	visit[index] = true;
	for (int i=0; i<arr[index].size(); i++) {
		int next = arr[index][i];
		
		if (visit[next] == false ) {
			Dfs(next, depth + 1 );
		}
		
	}
	visit[index] = false;	
}

int main() {
	
	cin >> n >> m;
	for( int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for ( int i=0; i<n; i++) {
		Dfs(i, 0);
		if(ans) {
			break;
		}
	}
	
	cout << ans;
 	
	return 0;
}


