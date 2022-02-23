#include <iostream>
#include <vector>

using namespace std;

bool prime_number(int num)
{
	if(num < 2)
	{
		return false;
	}
	for(int i=2; i*i<= num; i++)
	{
		if( (num%i) == 0)
		{	
			return false;
		}
	}		
	cout << num << '\n';
	return true;
}
int main()
{
	int input[2];
	int j;
	
	for (int i = 0; i<2; i++)
	{
		cin >> input[i];
	}
	
	j = input[0];
		
	for( j; j <= input[1]; j++)
	{
		prime_number(j); 
	}
	
	return 0;
}
