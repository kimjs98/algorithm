#include <cstring>
#include <iostream>

using namespace std;

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

int map[51][51];
bool check[51][51];
int w, h;

void Dfs(int row, int col)
{
	check[row][col] = true;
	for(int i=0; i<8; i++)
	{
		int x = row + dx[i]; // row  
		int y = col + dy[i]; // col 
		
		if( x>=0 && x<h && y>=0 && y<w )
		{
			if( map[x][y] && !check[x][y] )
				Dfs(x, y);
		}
	} 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while(1)
	{	
		cin >> w >> h;
		if( !w && !h )
			break;
		
		int i, j;
		for(i=0; i<h; i++)
		{
			for(j=0; j<w; j++)
			{
				cin >> map[i][j]; 
			}
		}	
		
		int islands = 0;	
		for(i=0; i<h; i++)
		{
			for(j=0; j<w; j++)
			{
				if( !check[i][j] && map[i][j] )
				{	
					islands++;
					Dfs(i, j);	
				}
			}
		}	
		cout << islands << '\n';
		
		memset(check, false, sizeof(check));
		memset(map, false, sizeof(map));		
	}
	return 0;
}
