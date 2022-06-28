#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int check[301][301];

int dx[] = {-1, 1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, -1, 1};

queue<pair<int,int>> cur, goal;

void Bfs(int x, int y, int length)
{
	int goal_x, goal_y;
	cin >> goal_x >> goal_y;
	
	if( x == goal_x && y == goal_y)
		cout << 0 << '\n';
	
	queue<pair<int,int>> q;
	check[x][y] = true;
	
	q.push( pair<int,int>(x,y) );
	
	while(!q.empty()){
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i=0; i<8; i++){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if( nx>=0 && nx<length && ny>=0 && ny<length )
			{
				if( check[nx][ny] == 0 )
				{		
					check[nx][ny] = check[x][y] + 1;
					q.push( pair<int,int>(nx,ny));
					
					if( nx == goal_x && ny == goal_y)
						cout << check[nx][ny]-1 << '\n';
				}
			}
		}
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	
	while(testcase--){
		
		memset(check, false, sizeof(check));
		int l;
		cin >> l;
		
		int a,b;
		cin >> a >> b;
		Bfs(a, b, l);
			
	}

	return 0;
}
