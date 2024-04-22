#include <algorithm>
#include <iostream>

#define MAX 100001
using namespace std;

int dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i=1; i<=n; ++i) {

		dp[i] = i;
		for(int j=1; j*j<=i; ++j)
// n에서 i제곱을 뺏을 때 나올 수 있는 모든 개수 중 최소가 되는 값 찾기. 
			dp[i] = min(dp[i], dp[i-j*j] + 1);

	}

	cout << dp[n];
	return 0;
}
