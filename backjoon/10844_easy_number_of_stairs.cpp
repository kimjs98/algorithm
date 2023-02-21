#include <iostream>

#define MAX 101
#define MOD 1000000000
using namespace std;

long long dp[MAX][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=1; i<10; i++) {
		dp[1][i] = 1;
	}
	
	for(int i=2; i<=n; i++) {
		
		dp[i][0] = dp[i - 1][1] % MOD;
		dp[i][9] = dp[i - 1][8] % MOD;
		
		for(int j=1; j<9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}

	long long num = 0;
	for(int i=0; i<10; i++) {
		num += dp[n][i];
	}
	
	cout << num % MOD;

	return 0;
}
