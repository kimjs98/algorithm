#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(3);
	
	for( int i=0; i<3; i++)
	{
		cin >> v[i];
		
	}
	
	cout << (v[0]+v[1])%v[2] << '\n';
	cout << (v[0]%v[2] + v[1]%v[2])%v[2] << '\n';
	cout << (v[0]*v[1])%v[2] << '\n';	
	cout << (v[0]%v[2] * v[1]%v[2])%v[2];
	
	return 0;
}

