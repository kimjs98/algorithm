#include <algorithm> 
#include <iostream>

using namespace std;

const int MAX = 21;
int map[MAX][MAX];
//int tmp[MAX][MAX];

int n, ans;

/*
	구역을 5개 선거구로 나눔. 각 구역은 다섯 선거구 중 하나에 포함.
	a -> b 로 갈수있는 경우 두 구역은 연결. 

*/ 

// x = r , y = c
int CheckMin(int x, int y, int d1, int d2) {

	int sum[5] = {0, };
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {

			if(i < x + d1 && j <= y && !(i >= x && j >= y - (i - x)))
				sum[0] += map[i][j];
			else if(i <= x + d2 && j > y && !(i >= x && j <= y + (i - x)))
				sum[1] += map[i][j];
			else if(i >= x + d1 && j < y - d1 + d2 && 
				!(i <= x + d1 + d2 && j >= (y - d1 + d2 - (x + d1 + d2 - i))))
				sum[2] += map[i][j];
			else if(i > x + d2 && j >= y - d1 + d2 && 
				!(i <= x + d1 + d2 && j <= (y - d1 + d2 + (x + d1 + d2 - i))))
				sum[3] += map[i][j];
			else
				sum[4] += map[i][j];
		}
	}
	
	sort(sum, sum + 5);
	
	return sum[4] - sum[0];
}

void Simulation(int r, int c) {
	//cout << "point : "<< r << ' ' << c << '\n';
	 
	// d1, d2 선정 
	for(int d1 = 1; d1 < c; ++d1) {
		for(int d2 = 1; d2 + c <= n; ++d2) {
			if(d1 + d2 + r > n) continue;
			//cout << d1 << ' ' << d2 << '\n';

			int ret = CheckMin(r, c, d1, d2);
			ans = min(ans, ret);	
		}
	}

	//cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)	cin >> map[i][j];
	
	ans = 2147000000;
	for(int i=1; i+2<=n; ++i) {
		for(int j=2; j+1<=n; ++j) {
			Simulation(i, j);
		}
	}
	cout << ans;

	return 0;
}
