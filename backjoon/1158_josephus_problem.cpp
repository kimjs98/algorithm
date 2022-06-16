#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	int i;	
	for(i=1; i<=n; i++)
	{
		q.push(i);
	}
	
	int temp;
	
	cout << "<";
	while(q.size()-1)
	{
		for(i=0; i<k-1; i++)
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}
			
		cout << q.front() <<", ";	
		q.pop();
	}
	
	cout << q.front() <<">";
	q.pop();
	
	return 0;
}
