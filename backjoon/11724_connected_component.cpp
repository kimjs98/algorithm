#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool check[499500];
vector<int> arr[499500];

int cnt;

void Dfs(int index, int depth)
{
	check[index] = true;
	
	for (int i=0; i<arr[index].size(); i++)
	{
		int next = arr[index][i];
		
		if(check[next] == false)
		{
			Dfs(next, depth+1);	
		}
	}
	
}


int main()
{
	cin >> n >> m;
	
	int a,b;
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
	} 
	
	for(int i=1; i<=n; i++)
	{
		Dfs( i, 0);
	}
	
	return 0;
}

