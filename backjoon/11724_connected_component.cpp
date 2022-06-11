#include <iostream>
#include <vector>

using namespace std;

bool check[1001];
vector<int> arr[1001];

void Dfs(int index, int depth)
{
	check[index] = true;
	for (int i=0; i<arr[index].size(); i++)
	{
		int next = arr[index][i];
		if(check[next] == false )
		{
			Dfs(next, depth+1);	
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	
	int a, b;
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	} 

	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		if (check[i] == false)
		{
			Dfs(i, 0);
			cnt++;	
		}
	
	}
	cout << cnt;
	
	return 0;
}
