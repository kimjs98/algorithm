#include <iostream>
#include <vector>
using namespace std;

bool prime_number(int num)
{
	if(num < 2){
		return false;
	}
		
	for(int i=2; (i*i)<= num; i++)
	{
		if( (num%i) == 0 )
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
			
		if( prime_number(v[i]) == 1 )
		{
			cnt++;
		}
			
	}
	cout << cnt;
	
	return 0;
}

