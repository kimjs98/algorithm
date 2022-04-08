#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maximize(int n, vector<int> &arr)
{
	int ans = 0;
	
	for( int i=2; i <= n; i++)
	{
		ans += abs(arr[i-2]-arr[i-1]);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	
	int err;
	int ans = 0, temp = 0;
	while(1)
	{
		temp = maximize(n,arr);
		if(temp>ans)
		{
			ans = temp;	
		}
		err = next_permutation(arr.begin(), arr.end());
		if(!err)
			break;	
	}
	cout << ans;	

		
	return 0;
}
