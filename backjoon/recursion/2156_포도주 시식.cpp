#include <algorithm>
#include <iostream>

#define MAX 10001
using namespace std;

int dp[MAX];
int arr[MAX];
// �������� ���� 3���� ��� ���� ���� ����.
// ���� ���� ���� �����ָ� ���� �� �ֵ��� �ϴ� ���α׷� �ۼ�. 
/*
	dp[i] : i��° ������ 
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
