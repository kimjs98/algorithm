#include <algorithm>
#include <iostream>

#define MAX 1001
using namespace std;

int map[MAX][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		
		map[i][0] = min(map[i-1][1], map[i-1][2]) + r; 
		map[i][1] = min(map[i-1][0], map[i-1][2]) + g;
		map[i][2] = min(map[i-1][0], map[i-1][1]) + b;
	}
	
	int cost = min(map[n][0], min(map[n][1], map[n][2]));
	cout << cost;

	return 0;
}

