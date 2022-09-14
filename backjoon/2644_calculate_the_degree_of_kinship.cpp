#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check[101];
vector<int> arr[101];

int n;
int p1, p2, m;
int ans;

void Dfs(int index, int depth) {

	if(index == p2) {
		ans = depth;
	}
	
	check[index] = true;
	for( int i=0; i<arr[index].size(); i++) {
		int next = arr[index][i];
		
		if(check[next] == false)
			Dfs(next, depth+1);
	}

}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> p1 >> p2 >> m;
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	Dfs(p1, 0);
	
	if(ans)	cout << ans;
	else	cout << -1;
	
	return 0;
}
