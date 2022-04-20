#include <iostream>
#include <vector>
using namespace std;

int cnt;
void search(int sum, int goal)
{
	cout << sum << '\n';
	if(sum == goal )
	{
		cnt += 1;
		cout << "return in sum == goal" << '\n';
		return;
	}
	else if(sum > goal)
	{
		cout << "return in sum > goal" << '\n';
		return;
	}
	else;
	
	for(int i= 1; i<=3; i++)
	{
		search(sum+i, goal);
	}
	
}

int main(void)
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		cnt = 0;
		search( 0, n);
		
		cout << cnt << '\n';
	}
	 
	return 0;
}
