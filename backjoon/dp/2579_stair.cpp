#include <algorithm>
#include <iostream>

#define MAX 301
using namespace std;

int stair;
int score[MAX];

/*
int dp[MAX][3];

// dp[i][j] : 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 
// 올라섰을 때 점수 합의 최대값, 단 i번쨰 계단은 반드시 밟아야 함 

// dp[k][1] : 현재까지 1개의 계단을 연속해서 밟고 k번째 계단까지 
// 올라섰을 때 점수 합의 최대값 

// dp[k][1] = score[k] + max(dp[k-2][1], dp[k-2][2]);
// dp[k][2] = score[k] + dp[k-1][1];
*/

int dp[MAX];

// dp[i] : i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최솟값, 
// 단 i번째 계단은 반드시 밟지 않을 계단으로 선택 

/*
	dp[k] = min(dp[k-1], min(dp[k-2], dp[k-3]) + score[k]; 

	k번째 계단을 밟지 않은 경우 k-1은 무조건 밟아야함, 
	k-2나 k-3중하나는 무조건 밟아야 함 
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> stair;
	for(int i=1; i<=stair; ++i) {
		cin >> score[i];
	}

/*	
	if(stair == 1) cout << score[1];
	else {
		dp[1][1] = score[1];
		dp[1][2] = 0;
		dp[2][1] = score[2];
		dp[2][2] = score[1] + score[2]; 
		
		for(int i=3; i<=stair; ++i) {
			dp[i][1] = score[i] + max(dp[i-2][1], dp[i-2][2]);
			dp[i][2] = score[i] + dp[i-1][1];
		}
		
		int ans = max(dp[stair][1] , dp[stair][2]);
		cout << ans;
	}
*/	
	return 0;
}
