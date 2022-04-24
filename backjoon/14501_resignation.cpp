#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int n;
vector<int> t(16), p(16);	

void dfs(int day, int sum)
{
	if(day == n+1)
	{
		if( sum > ans) 
			ans = sum;
			
		return;
	}
	
	if(day > n+1)
	{
		return;
	}
	
	dfs(day + t[day], sum + p[day] );
	dfs(day + 1, sum );
}

int main()
{	
	cin >> n;	
	for(int i=1; i<=n; i++)
	{
		cin >> t[i] >> p[i];
	}
	
	dfs(1, 0);		
	cout << ans << '\n';

	return 0;
}

