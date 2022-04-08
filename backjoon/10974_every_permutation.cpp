#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,err;
	cin >> n;
	vector<int> arr(n);
	
	
	for(int i=0; i<n; i++)
	{
		arr[i] = i+1;
		cout << arr[i] << ' '; 
	}
	cout << '\n';
	
	while(1)
	{
		err = next_permutation(arr.begin(),arr.end());
		if(!err)
			break;
		
		for(int i=0; i<n; i++)
		{
			cout << arr[i] << ' '; 
		}
		cout << '\n';	
	}
	
	return 0;
}

