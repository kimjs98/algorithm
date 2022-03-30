#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	vector <int> p(n+1);	//	n��° ī������ ����  
	vector <int> d(n+1);	//	ī�� n���� �����ϴ� �ִ� ���  
	
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
