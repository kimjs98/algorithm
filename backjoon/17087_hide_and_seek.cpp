#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{	
	int n; // 1 <= n <= 10^5
	int s; // 1 <= s <= 10^9
	
	int ans; 

	cin >> n >> s;
	
	vector<int> a(n);

	for( int i=0; i<n; i++ )	
	{
		cin >> a[i];
		a[i] = abs(s-a[i]);
	}
	
	ans = a[0];
	for(int i= 1; i<n; i++)
	{
		ans = gcd(ans, a[i]);	
	}	
	cout << ans;
		

	return 0;	
}
