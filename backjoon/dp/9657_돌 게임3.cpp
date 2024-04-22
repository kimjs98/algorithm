#include <algorithm>
#include <iostream>

#define MAX 1001 
using namespace std;

int dp[MAX]; // dp[i] : 돌이 i개일 때 상근이가 이김.  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	dp[1] = dp[3] = dp[4] = 1;
	
	for(int i=5; i<=n; ++i) {
		if(min({dp[i - 1], dp[i - 3], dp[i - 4]}) == 1) dp[i] = 0;
		else											dp[i] = 1; 
	}

	if(dp[n]) 	cout << "SK";
	else		cout << "CY";

	return 0;
}

