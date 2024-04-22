#include <algorithm>
#include <iostream>

#define MAX 1001
using namespace std;

int arr[MAX]; 
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> arr[i];
		dp[i] = arr[i];	
	}

/*
	j 
	1 
	1 2
	1 2 3
	
*/
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=i; ++j) {
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}
