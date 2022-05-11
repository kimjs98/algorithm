#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m;
	string str;
	int input, bit= 0;	
	
	cin >> m;
	while(m--)
	{
		cin >> str;
		if( str == "add")
		{
			cin >> input;
			bit |= (1 << input); 
		}
		else if( str == "remove")
		{
			cin >> input;
			bit &= ~(1 << input); 	
		}
		else if( str == "check")
		{
			cin >> input;
			
			if( bit & (1 << input) )
				cout << true << '\n';
			else
				cout << false << '\n'; 
		}
		else if( str == "toggle")
		{
			cin >> input;
			bit ^= (1 << input);
		}
		else if( str == "all")
		{
			bit |= (1 << 21) - 1;
		}
		else if( str == "empty")
		{
			bit = 0;
		}
	}	
	
	return 0;
}
