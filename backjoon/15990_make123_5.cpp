#include <iostream>

#define MAX 100001
#define MOD 1000000009
using namespace std;

long long int dy[MAX][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int testcase;
	cin >> testcase;

	dy[1][1] = dy[2][2] = 1;
	dy[3][1] = dy[3][2] = dy[3][3] = 1;

	for(int i=4; i<MAX; i++) {
		dy[i][1] = (dy[i - 1][2] + dy[i - 1][3]) % MOD;
		dy[i][2] = (dy[i - 2][1] + dy[i - 2][3]) % MOD;
		dy[i][3] = (dy[i - 3][1] + dy[i - 3][2]) % MOD;
	}

	while(testcase--) {
		int n;
		cin >> n;

		cout << (dy[n][1] + dy[n][2] + dy[n][3]) % MOD << '\n';
	}

	return 0;
}
