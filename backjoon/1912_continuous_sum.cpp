#include <algorithm>
#include <iostream>

#define MAX 100001
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	long long arr[n + 1] = {0, };
	int dp[n + 1] = {0, };

	// 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합 
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	long long ans = arr[0];
	for(int i=0; i<n-1; i++) {
		arr[i + 1] += arr[i];
		if(arr[i] < arr[i - 1]) {
			ans = max(ans, arr[i]);

		}
		else {

		}
	}

	cout << '\n';
	cout << ans;

	return 0;
}
