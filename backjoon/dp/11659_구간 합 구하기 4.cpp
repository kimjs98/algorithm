#include <algorithm>
#include <iostream>

#define MAX 100001
using namespace std;

int dp[MAX]; 
int num[MAX];
// �� n���� �־����� ��, i��° ������ j��° ������ ���� ���ϴ� ���α׷� 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	dp[0] = 0;
	for(int i=1; i<=n; ++i) {
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];		
	}

	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b; // ���� 
		
		int ans = dp[b] - dp[a - 1];
		cout << ans << '\n';
	}
	return 0;
}

