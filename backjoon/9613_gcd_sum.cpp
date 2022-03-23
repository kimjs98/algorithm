#include <iostream>
#include <vector>
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
	int t,n;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> v(n);
		
		for(int i=0; i<n; i++)
		{
			cin >> v[i];	
		}
		
		long long result=0;
		
		for(int i=0; i<n; i++)
		{	
			for(int j=i+1; j<n; j++)
			{
				result += gcd(v[i],v[j]);			
			}	
		}
		cout << result << '\n';
	}	
	return 0;
}
