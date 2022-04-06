#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	int debug = 0;	
	debug = next_permutation(arr.begin(), arr.end());
	
	if(!debug)
	{
		debug = -1;
		cout << debug;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			cout << arr[i] << ' ';
		}
	}
	
	
	return 0;
}

