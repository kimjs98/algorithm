#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX	1001

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int m, n;

int map[MAX][MAX];
int dist[MAX][MAX];

queue<pair<int,int>> q;
 
void Bfs(void)
{
	while(!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;	
		
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if( nx>=0 && nx<m && ny>=0 && ny<n )
			{
				if( !map[ny][nx] && !dist[ny][nx] ) 
 				{
					q.push( pair<int,int>(ny,nx) );
					dist[ny][nx] = dist[y][x] + 1;
					
					cout<< " ny, nx : " << ny << " "<< nx << '\n';
				}
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				dist[i][j] = map[i][j];
				q.push( pair<int,int>(i,j) );
			}
			else if(map[i][j] == -1)
			{
				dist[i][j] = map[i][j];
			}
			else;
		}
	}
	
	Bfs();

	int ans = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if ( ans < dist[i][j] )
			{
				ans = dist[i][j];
			}
			
			if( dist[i][j] == 0 )
			{
				cout << -1;
				return 0;
			}	
		}
	}
	
	cout << --ans;
	return 0;
}
