#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>

#define MAX 100001
using namespace std;

int n, m;
int w[MAX];
bool check[MAX];
vector<int> v[MAX];

bool CalBestMember(int num) {	
	if(v[num].empty()) return 1;

	bool flag = false;
	for(int i=0; i<v[num].size(); i++) {
		int next = v[num][i];
		if(w[next] < w[num]) {
			flag = 1;
		}
		else	return 0;
	}
	
	return flag;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> w[i];
	}
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++) {
	 	ans += CalBestMember(i);
	}
	cout << ans;
	
	return 0;
}
