#include <algorithm>
#include <iostream>

#define MAX 501
using namespace std;

int dp[MAX][MAX];
int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=i; ++j)
			cin >> map[i][j];
	}

	dp[1][1] = map[1][1];	
	for(int i=2; i<=n; ++i) {
		for(int j=1; j<=i; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
		}
	}

	/*
	int ans = map[1][1];
	for(int i=1; i<=size; ++i)
		ans = max(ans, dp[n][i]);
	cout << ans;
	*/
	cout << *max_element(dp[n] + 1, dp[n] + n + 1);	

	return 0;
} 
