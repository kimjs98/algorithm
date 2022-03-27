#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin >> n; 
	vector <int> d(n+1);
	
	d[1] = 1;
	d[2] = 2;
	
	for(int i = 3; i < n+1; i++ )
	{
		d[i] = ( d[i-1] + d[i-2] )%10007 ;	
	}
	cout << d[n] << '\n';
	
	return 0;
}
