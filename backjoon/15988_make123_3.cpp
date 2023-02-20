#include <iostream>

#define MAX 1000001
using namespace std;

long long dy[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	
	dy[1] = 1;
	dy[2] = 2;
	dy[3] = 4;
	
	for(int i=4; i<MAX; i++) {
		dy[i] = (dy[i - 1] + dy[i - 2] + dy[i - 3]) % 1000000009;
	}
	
	while(testcase--) {
		int n;
		cin >> n;
		
		cout << dy[n] << '\n';
	}
	
	return 0;
}

