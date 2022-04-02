#include <iostream>
using namespace std;

int arr[500][500];


int main()
{
	int n, m;
	int ans = 0, max_value = 0;

	cin >> n >> m;
	
	for( int i=0; i<n; i++ )
	{
		for( int j=0; j<m; j++ )
		{
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			
			/*tetromino 1*/ 
			if( j+3 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
				
				if( max_value > ans )
					ans = max_value;
			}
			if ( i+3 < n )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
				
				if( max_value > ans )
					ans = max_value;
			}			
				
			
			/*tetromino 2*/ 
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+2];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i][j+2];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i+2][j] +arr[i+2][j+1] + arr[i+1][j+1] + arr[i][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];  
				 
				if( max_value > ans )
					ans = max_value;
			}
			
			/*	tetromino 3 */
			if( i+1 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			/*	tetromino 4 */
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i+1][j] + arr[i+1][j+1] + arr[i][j+1] + arr[i][j+2];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+2][j];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			/*	tetromino 5 */ 
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			
			if( i+1 < n && j+2 < m )
			{
				max_value = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			if( i+2 < n && j+1 < m )
			{
				max_value = arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
				
				if( max_value > ans )
					ans = max_value;
			}
			
			
			
		}
			
	} 
	
	cout << ans;
	
	
	
	
	
	return 0;
}
