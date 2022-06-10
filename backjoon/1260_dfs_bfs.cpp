#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;	


bool check[10001];
vector<int> arr[10001];

void Dfs( int index, int depth)
{
	cout << index << ' ';
		
	check[index] = true;
	for(int i=0; i<arr[index].size(); i++)
	{
		int next = arr[index][i];
		if(check[next] == false)
			Dfs(next, depth + 1 );
	}	
	
}

void Bfs(int index)
{
	queue<int> q;
	
	check[index] = true; 
	q.push(index);
	
	while(!q.empty()) 
	{
		int x = q.front(); 
		q.pop();
		
		cout << x << ' ';
		
		for( int i=0; i<arr[x].size(); i++)
		{
			int next = arr[x][i];
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);  // 방문하지 않는 노드 push  
					
			}
		}	
	}	
	
}

int main()
{
	int n,m,v;
	cin >> n >> m >> v;
	
	int a, b;
	for(int i=0; i<m; i++) 
	{
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	for( int i=1; i<=n; i++)
	{
		sort( arr[i].begin(), arr[i].end() ); 
	}
	
	Dfs(v, 0);
	
	cout << '\n';
	memset(check, false, sizeof(check));
	
	Bfs(v);
	
	
	return 0;
}
