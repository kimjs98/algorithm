#include <iostream>
using namespace std;

int 	ans[9];
bool	decide[9];		// true or false
int		index = 0;		// 0 ~ m-1

void search(int index, int n, int m)
{
	//cout << "index : " << index << '\n';
	if(index == m)
	{	
		for(int i=0; i<m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(decide[i]) 
			continue;

		decide[i] = true;
		ans[index] = i;
		
		cout << "ans :" << ans[index] << '\n';
		
		search(index+1, n, m);
	
		decide[i] = false;
		cout << "i : " << i << " index : " << index << '\n';	
	}	
}

int main()
{
	int n,m;
	cin >> n >> m;
	
	search(0,n,m);
	
	
	return 0;
}

