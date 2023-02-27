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
	/* 이전 값 중에서 현재 값보다 작은 값인 경우, 그 수가 가지고 있는 부분 수열의 길이 중
		가장 긴 부분 수열의 길이에 + 1을 한 값이 현재 값에서 가장 긴 증가 부분 수열  */
	for(int i=0; i<n; i++) {
	
		dp[i] = 1;
		//cout << "i : " << i << " j : ";
		for(int j=0; j<i; j++) {
		//	cout << j << ' ';
			if(arr[i] > arr[j])	dp[i] = max(dp[i], dp[j] + 1);
		}
		//cout << '\n';
		length = max(length, dp[i]);
		//cout << length << ' ';
	}
	//cout << '\n';
	cout << length;

	return 0;
}
