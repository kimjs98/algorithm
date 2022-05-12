#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n,s;
	cin >> n >> s;
	
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	int ans = 0;
	for (int i=1; i< (1<<n); i++)  // check all bits 
	{
		int sum = 0;
		for(int j=0; j<n; j++)
		{
			if( i & (1<<j) )	
				sum +=arr[j];
		}

		if(sum == s)
			ans++;		
	}	
	cout << ans;	
		
	return 0;
}
