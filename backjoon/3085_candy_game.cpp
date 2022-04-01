#include <iostream>
#include <algorithm>

using namespace std;
char arr[51][51];

int ans = 0;

void row_search(int n)		
{	
	for (int i=0; i<n; i++)
	{
		int candy = 1;
	
		for (int j=0; j<n; j++)
		{
			if( arr[i][j] == arr[i][j+1] )
				candy++;
			else
			{
				if( candy > ans)	
					ans = candy;	// max value 
					
				candy = 1;
			}				
		}
	}					
}
void column_search(int n)		
{
	for (int i=0; i<n; i++)
	{
		int candy = 1;	
		
		for (int j= 0; j < n; j++)
		{
			if( arr[j][i] == arr[j+1][i] )
				candy++;
			else
			{
				if( candy > ans)	// max value 
					ans = candy;
					
				candy = 1;
			}				
		}
	}			
}

int main()
{	
	int n;
	cin >> n;

	for ( int i=0; i<n; i++)
	{
		for( int j=0; j<n; j++)
		{
			cin >> arr[i][j];	
		}
	}
	

	
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{		
			swap(arr[i][j], arr[i][j+1]); // row candy swap
				
			row_search(n); 
			column_search(n); 
					
			swap(arr[i][j+1], arr[i][j]);   	
		}
	}

	for (int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			swap(arr[j][i], arr[j+1][i]); // column candy swap
		
			row_search(n); 
			column_search(n); 
			
			swap(arr[j+1][i], arr[j][i]); 
		}
	}
	cout << ans; 
	
	return 0;
}
