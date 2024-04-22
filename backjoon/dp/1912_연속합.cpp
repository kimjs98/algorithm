#include <algorithm>
#include <iostream>

#define MAX 100001
using namespace std;

int dp[MAX];
int num[MAX];

/*
	���ӵ� ��� ���� �� �� ���� ū �� 
	dp[i] = i��°������ �� �߿��� ���ӵ� ���� �ִ밪. �ݵ�� i��° �� ���� 
	i��° �ε����� ������ ������ �� �ִ밪 
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
