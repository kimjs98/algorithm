#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 101
using namespace std;

int n, m, ans;
bool check[MAX];
vector<int> v[MAX];

void Dfs(int n, int depth) {	

	check[n] = true;
	for(int i=0; i<v[n].size(); i++) {
		int next = v[n][i];
		if(!check[next]) {
			Dfs(next, depth + 1);
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	Dfs(1, 0);
	cout << ans;
	
	return 0;
}
