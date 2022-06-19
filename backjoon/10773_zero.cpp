#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int k;
	cin >> k;
	
	stack<int> s;
	int i, num; 
	
	for(i=0; i<k; i++)
	{
		cin >> num;
		
		if(!num)
			s.pop();
		else	
			s.push(num);
	}
	
	int ans = 0;
	while(!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	cout << ans;
	
	return 0;
}
