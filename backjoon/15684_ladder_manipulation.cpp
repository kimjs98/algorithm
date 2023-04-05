#include <iostream>

using namespace std;

#define MAX 31

bool map[MAX][MAX];
int n, m, h;
int ans, cnt;

/*
	n개의 세로, m개의 가로선 존재.
	인접한 세로선 사이에는 h개의 가로선을 놓을 수 있다.

	세로선과 가로선이 교차하는 지점이 가로선을 놓을 수 있는 점.
	* 가로선은 인접한 두 세로선을 연결하며, 두 가로선이 연속하거나 접하면 안 된다. 

	-> 사다리에 가로선을 추가해서, 사다리 게임 결과 조작.
	* i번 세로선의 결과가 i번이 나오도록 가로선 개수 추가. 
*/

void AddLine(int depth, int y, int x);
bool Checking();
int Ladder(int num);

void Input() {
	cin >> n >> m >> h;
	for(int i=0; i<m; i++) {
		int a, b;

		cin >> a >> b;
		map[a][b] = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	
	int ret = Checking();
	if(ret) {
		for(int i=1; i<=3; i++) {
			cnt++;
			AddLine(0, 1, 1);
		}
		ans = -1;
	}
	else ans = 0;

	cout << ans;

	return 0;
}

void AddLine(int depth, int y, int x) {
	
	if(depth == cnt) {
		
		int ret = Checking();
		if(!ret) {
			cout << cnt;
			exit(0);
		}

		/*
		cout << "check map depth : " << depth << '\n';
		for(int i=1; i<=h; i++) {
			for(int j=1; j<n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		return;
	}

	for(int i=y; i<=h; i++) {
			for(int j=x; j<n; j++) {
				if(!map[i][j]) {
					if(map[i][j - 1] || map[i][j + 1]) continue;
					
					map[i][j] = true;
					AddLine(depth + 1, i, j + 1);
					map[i][j] = false;
					
				}
			}
			x = 1;
		}

}

bool Checking() {

	for(int i=1; i<=n; i++) {
		int number = Ladder(i);
		if(number != i)	return true; 
	}
	
	return false;
}

int Ladder(int num) {
	for(int i=1; i<h+1; i++) {
		if(map[i][num]) num++;
		else if(map[i][num - 1]) num--;
		else;
		
	}	

	return num;
}
