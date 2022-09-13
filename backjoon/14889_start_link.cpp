#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ans = 99999999;
bool check[21];
int arr[21][21];

int n;

void dfs(int player, int cnt)
{	
	if(player == n/2)
	{
		int team_start = 0;
		int team_link = 0;
		
		for(int i=1; i<=n; i++)
		{
			
			for(int j=1; j<=n; j++)
			{
				if(i==j) 
					continue;
			
				if( check[i] && check[j])	team_start += arr[i][j];
				if( !check[i] && !check[j]) team_link += arr[i][j];		
			}
		}
		
		ans = min(ans, abs(team_start-team_link));		
		return;
	}
	
	if( cnt > n )	return;
	
	check[cnt] = true;
	dfs(player+1,cnt+1);
	check[cnt] = false;
	dfs(player, cnt+1); 
}

int main()
{
	cin >> n;	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> arr[i][j];
		}
	}
		
	dfs(0, 1);
	cout << ans;
	
	return 0;
}
