#include <iostream>

using namespace std;

#define MAX 31

bool map[MAX][MAX];
int n, m, h;
int ans, cnt;

/*
	n���� ����, m���� ���μ� ����.
	������ ���μ� ���̿��� h���� ���μ��� ���� �� �ִ�.

	���μ��� ���μ��� �����ϴ� ������ ���μ��� ���� �� �ִ� ��.
	* ���μ��� ������ �� ���μ��� �����ϸ�, �� ���μ��� �����ϰų� ���ϸ� �� �ȴ�. 

	-> ��ٸ��� ���μ��� �߰��ؼ�, ��ٸ� ���� ��� ����.
	* i�� ���μ��� ����� i���� �������� ���μ� ���� �߰�. 
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
