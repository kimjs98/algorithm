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

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int length = 1;
	for(int i=0; i<n; i++) {

		dp[i] = 1;
		//cout << "i : " << i << " j : ";
		for(int j=0; j<i; j++) {
			//cout << j << ' ';
			if(arr[i] > arr[j])	dp[i] = max(dp[i], dp[j] + 1);
		}
		//cout << '\n';
		length = max(length, dp[i]);
	}
	//cout << '\n';
	cout << length;

	return 0;
}
