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

int lcm(int a, int b)
{
	int c;
	int init_a = a;
	int init_b = b;
	
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a*(init_a/a)*(init_b/a);
}

int main()
{
	vector<int> v(2);
	
	for( int i=0; i<2; i++)
	{
		cin >> v[i];
	}
	
	cout << gcd(v[0],v[1]) << '\n';	
	cout << lcm(v[0],v[1]);	
	
	
	
	return 0;
}
