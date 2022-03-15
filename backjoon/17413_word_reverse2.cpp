#include <iostream>
#include <stack>
#include <string>

using namespace std;

void print_str(stack <char> &s)
{
	while(!s.empty()) // 
	{
		cout << s.top();
		s.pop();		
	}
}

int main()
{
	string str;
	getline(cin, str);
	
	bool reverse_flag = false;
	stack<char> s;	

	for(char ch : str)	// check each str 
	{
		if(ch == '<')
		{
			print_str(s);	
			reverse_flag = true;
			cout << ch;
		}
		else if(ch == '>' )
		{
			print_str(s);
			reverse_flag = false;
			cout << ch;	
		}
		else if(reverse_flag)
		{
			cout << ch;		
		}
		else
		{
			if(ch == ' ')
			{
				print_str(s);
				cout << ch;
			}
			else
				s.push(ch);
		}		
	}
	
	print_str(s); // last word reverse  	
	return 0;
}
