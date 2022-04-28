#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 999999999;
bool check;
int s[21][21];

void dfs(int index)
{
	if(index == n/2)
	{
		int team_start = 0;
		int team_link = 0;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				
				team_start += s[i][j];
				team_link += s[i][j];
			}
		}
		
		int temp = abs(team_start-team_link);
		if( ans > temp) ans = temp;	
	}
	
	//if( index > n/2 )	return;
	
	for(int i=0; i<n; i++)
	{
		check[i] = false;
		
		dfs(index+1);
		
		check[i] = true;
			
	}
	
	
}


int main()
{
	cin >> n;	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> s[i][j];
		}
	}
	dfs(0);
	
	return 0;
}
