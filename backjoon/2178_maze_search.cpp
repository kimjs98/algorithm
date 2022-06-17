#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;

int map[101][101];
int dist[101][101];

bool check[101][101];

void Bfs(int y, int x)
{
	queue<pair<int,int>> q;
	
	check[y][x] = true;
	dist[y][x] = 1;
	
	q.push( pair<int,int>(y,x) );

	while(!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;	
		
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if( nx>=0 && nx<m && ny>=0 && ny<n)
			{
				if( map[ny][nx] && !check[ny][nx] )
				{
					check[ny][nx] = true;
					q.push( pair<int,int>(ny,nx));
					
					dist[ny][nx] = dist[y][x] + 1;
				}
			}	
		} 
	}	
	cout << dist[n-1][m-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	string str;
	int i,j;
	
	for(i=0; i<n; i++)
	{
		cin >> str;
		for(j=0; j<m; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}		
	Bfs(0, 0);
	
	
	
	return 0;
}
