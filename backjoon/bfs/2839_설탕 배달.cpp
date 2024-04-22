#include <algorithm>
#include <iostream>

#define MAX 5001 
using namespace std;

int dp[MAX];

/*
	dp[i] : i 킬로그램 배달해야 할 때 필요한 봉지 개수 
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	fill(dp, dp + MAX, MAX);
	
	dp[3] = 1;
	dp[5] = 1;

	for(int i=6; i<=n; ++i) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	
	if(dp[n] > 5000) 		cout << -1;
	else					cout << dp[n];
	
	return 0;
}
