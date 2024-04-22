#include <algorithm>
#include <iostream>

using namespace std;

int fibonacci(int n) {
	if(n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	else if(n == 1) {
		cout << 1 << '\n';
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int dp[41];
// dp[i][0] : i가 주어졌을 때 0이 출력된 개수.
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	dp[1] = dp[2] = 1;
	for(int i=3; i<=40; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	int testcase;
	cin>> testcase;
	while(testcase--) {
		int n;
		cin >> n;
		
		if(!n)  cout << 1 << ' ' << 0 << '\n';
		else	cout << dp[n - 1] << ' ' << dp[n] << '\n';				
	}

	return 0;
}
