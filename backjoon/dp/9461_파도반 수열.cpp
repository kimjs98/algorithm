#include <algorithm>
#include <iostream>

#define MAX 101
using namespace std;

long long dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for(int i=6; i<MAX; ++i)
		dp[i] = dp[i - 1] + dp[i - 5];
	
	while(t--) {

		int n;
		cin >> n;
		cout << dp[n] << '\n';
	} 
		
	return 0;
} 
