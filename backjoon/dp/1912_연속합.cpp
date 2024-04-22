#include <algorithm>
#include <iostream>

#define MAX 100001
using namespace std;

int dp[MAX];
int num[MAX];

/*
	연속된 몇개의 수의 합 중 가장 큰 합 
	dp[i] = i번째까지의 수 중에서 연속된 수의 최대값. 반드시 i번째 수 포함 
	i번째 인덱스로 끝나는 연속합 중 최대값 
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i=1; i<=n; ++i) {
		cin >> num[i];
	}

	int ans = dp[1];
	for(int i=1; i<=n; ++i) {
		dp[i] = max(dp[i-1], 0) + num[i];
	}
	
	cout << *max_element(dp + 1, dp + n + 1); 

/*
	for(int i=1; i<=n; ++i)
		cout << dp[i] << ' ';
*/	
	return 0;
} 
