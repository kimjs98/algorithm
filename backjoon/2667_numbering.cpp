#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int map[25][25];
bool check[25][25];

int cnt, home;
vector<int> ans;

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void Dfs(int row, int col)
{
	cnt++;
	
	check[row][col] = true;
	
	for(int i=0; i<4; i++)
	{
		/* �����¿� ���� Ž�� */
		int x = row + dx[i]; 
		int y = col + dy[i];
		
		if( x>=0 && x<n && y>=0 && y<n )
		{
			if( map[x][y] && !check[x][y] )
			{
				Dfs(x, y);
			}			
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	
	int i,j; 
	string str;
	
	for(i=0; i<n; i++)
	{
		cin >> str;
		for(j=0; j<n; j++)
		{
			map[i][j] = str[j] - '0'; 		// �Ľ� 
		}
	}
	
	cnt = 0;
	home = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if( !check[i][j] && map[i][j]) 	// �湮�� ���� ���� ������ �ִ� ��� 
			{
				home++;		//���� �� ���� ī��Ʈ  
				
				Dfs(i, j);
				ans.push_back(cnt);	// ���� ũ�� push 
				cnt = 0;
			}
		}
	}
	cout << home <<'\n';
	
	sort( ans.begin(), ans.end() );
	for( int i=0; i<ans.size(); i++)
	{
		cout << ans[i] <<'\n';
	}

	return 0;
}
