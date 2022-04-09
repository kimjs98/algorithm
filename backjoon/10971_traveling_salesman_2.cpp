#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n);	// visiting sequence 
	int w[n][n];
	for( int i=0; i<n; i++)
	{
		for( int j=0; j<n; j++)
		{
			cin >> w[i][j]; 
		}
	}
	
	for(int i=0; i<n; i++)
	{
		d[i] = i;	
	}
	
	static bool once = true;	
	int ans;	
	
	do
	{
		bool flag = true;
		int temp = 0;
		
		for(int i=0; i<n-1; i++)
		{
			if( w[d[i]][d[i+1]] == 0 )
			{
				flag = false;
			} 
			else
				temp += w[d[i]][d[i+1]];	
		}
		
		if( w[d[n-1]][d[0]] != 0 && flag)
		{
			temp += w[d[n-1]][d[0]];
			
			if(once)
			{
				ans = temp;
				once = false;
			}
			else
			{
				if(temp < ans)
					ans = temp;	
			}
		}
	}
	while( next_permutation(d.begin(),d.end()) );
	cout << ans;

	return 0;
}
