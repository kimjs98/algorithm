#include<iostream>

#define MAX 15
#define endl '\n'

using namespace std;
int n;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int side = 2;	// 1 level side
	int dot = 1;
	
	for(int i=1; i<n+1; i++) {
		side += dot;
		dot *=2;
		
	}
	cout << side * side;
	
	return 0;
}
