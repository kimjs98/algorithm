#include <algorithm>
#include <iostream>

#define MAX 301
using namespace std;

int stair;
int score[MAX];

/*
int dp[MAX][3];

// dp[i][j] : ������� j���� ����� �����ؼ� ��� i��° ��ܱ��� 
// �ö��� �� ���� ���� �ִ밪, �� i���� ����� �ݵ�� ��ƾ� �� 

// dp[k][1] : ������� 1���� ����� �����ؼ� ��� k��° ��ܱ��� 
// �ö��� �� ���� ���� �ִ밪 

// dp[k][1] = score[k] + max(dp[k-2][1], dp[k-2][2]);
// dp[k][2] = score[k] + dp[k-1][1];
*/

int dp[MAX];

// dp[i] : i��° ��ܱ��� �ö��� �� ���� ���� ����� ���� �ּڰ�, 
// �� i��° ����� �ݵ�� ���� ���� ������� ���� 

/*
	dp[k] = min(dp[k-1], min(dp[k-2], dp[k-3]) + score[k]; 

	k��° ����� ���� ���� ��� k-1�� ������ ��ƾ���, 
	k-2�� k-3���ϳ��� ������ ��ƾ� �� 
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
