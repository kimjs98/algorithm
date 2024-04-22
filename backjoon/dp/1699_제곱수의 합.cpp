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
// n���� i������ ���� �� ���� �� �ִ� ��� ���� �� �ּҰ� �Ǵ� �� ã��. 
			dp[i] = min(dp[i], dp[i-j*j] + 1);

	}

	cout << dp[n];
	return 0;
}
