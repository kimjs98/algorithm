#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	 
	
	while(t--)
	{
		int n;
		cin >> n;
		
		vector <int> d(n+1);	
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		
		for(int i=4; i<n+1; i++)
		{
			d[i] = d[i-1] + d[i-2] + d[i-3];
		} 
			
		cout << d[n] << '\n';		
		
	}
	return 0;
}
