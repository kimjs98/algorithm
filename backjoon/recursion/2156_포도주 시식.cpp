#include <algorithm>
#include <iostream>

#define MAX 10001
using namespace std;

int dp[MAX];
int arr[MAX];
// 연속으로 놓인 3잔을 모두 마실 수는 없다.
// 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램 작성. 
/*
	dp[i] : i번째 포도주 
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> arr[num];		 
	}
	
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	
	for(int i=3; i<=n; ++i) {
		
	}
	
	return 0;
}
