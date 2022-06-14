#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int check[20001];
vector<int> arr[20001];

void Dfs(int index)
{
	if(check[index] == false)
		check[index] = 1;
		
	for(int i=0; i<arr[index].size(); i++)
	{
		int next = arr[index][i];
		if( check[next] == false )
		{
			if(check[index] == 1)		check[next] = 2;
			else if(check[index] == 2)	check[next] = 1;
			else;
			
			Dfs(next);	
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int k;
	cin >> k;
	
	/* test case */
	while(k--)
	{
		/* input */
		int v, e;
		cin >> v >> e;
		
		/* clear */
		for(int i=0; i<=v; i++)
		{
			arr[i].clear();
		}
		memset(check, false, sizeof(check));
		
			
		/* input edge */
		for(int i=0; i<e; i++)
		{
			int a, b;
			cin >> a >> b;
			
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
	
		/* search */
		for(int i=1; i<=v; i++)
		{
			if(check[i] == false)
				Dfs(i);
		}
		
		/* answer check */
		bool ok = false;
		for(int i=1; i<=v; i++)
		{		
			for(int j=0; j<arr[i].size(); j++)
			{
				int next = arr[i][j];
				if( check[i] == check[next] )
				{
					ok = true;
				}	
			}	
		}
		
		if(ok == false)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
			
	}
	
	return 0;
}

