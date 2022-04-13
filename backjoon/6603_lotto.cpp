#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> sel(13, 0);
 
void cal(int num)
{
	int k = num;
	vector<bool> ok(k, 0);	
	
	for(int i=0; i<k; i++)
	{
		cin >> sel[i];
	}
	for(int i=0; i<k; i++)
	{	
		if( i < k-(k-6) )
			ok[i] = true;
		else
			ok[i] = false;
	} 
	
	do
	{
		for(int i=0; i<k; i++)
		{
			if(ok[i])
				cout << sel[i] <<' ';
		}
		cout << '\n';
	}
	while(prev_permutation( ok.begin(),ok.end()) );	
}

int main()
{
	while(1)
	{
		int k;
		cin >> k;
		
		if(k==0)	
			break;

		cal(k);
		cout <<'\n';
	}
	
	return 0;
}
