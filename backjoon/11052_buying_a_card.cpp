#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	vector <int> p(n+1);	//	n번째 카드팩의 가격  
	vector <int> d(n+1);	//	카드 n개를 구매하는 최대 비용  
	
	for( int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	d[1] = p[1];
	
	for ( int i=1; i <= n; i++)
	{
		for( int j=1; j <= i; j++)
		{
			d[i] = max(d[i], d[i-j]+p[j]);
		}	
	}
	
	cout << d[n];			
				
				
				
	return 0;
}
