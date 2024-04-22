#include <algorithm> 
#include <iostream>

//#define DEBUG
using namespace std;

const int MAX = 21;
int map[MAX][MAX];
int map2[MAX][MAX];
//int arr[6];
int n, ans;


// �����¿� 0 1 2 3

// �ð���� 90�� ȸ�� 
void Rotate() {
	int tmp[MAX][MAX];
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			tmp[i][j] = map2[i][j];
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)	
			map2[i][j] = tmp[n - 1 - j][i];
}

void Move(int dir) {
	while(dir--) Rotate();	// ���⸸ŭ ȸ�� 
	for(int i=0; i<n; ++i) {
		int tmp[MAX] = {};	// map2[i]�� �������� ����� ����� ������ ���� 
		int idx = 0;		// tmp �迭���� ��� �����ؾ� �ϴ��� ����Ű�� ���� 
		for(int j=0; j<n; ++j) {
			if(!map2[i][j]) continue;
			
			if(!tmp[idx]) tmp[idx] = map2[i][j]; // ������ ��ġ�� �� -���
		 	else if(tmp[idx] == map2[i][j]) tmp[idx++] *= 2; // ���� ���� ���� ����� �浹�� ��� 
			else tmp[++idx] = map2[i][j]; 	// �ٸ� ���� ���� ����� �浹�� ���  
		}
		
		for(int j=0; j<n; ++j)
			map2[i][j] = tmp[j];
	}
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << map2[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int Game() {
	memcpy(map2, map, sizeof(map));
	
	int arr[6] = {0, 0, 1, 2, 3, 0};
	
	cout << "move start" << '\n';
	for(int i=0; i<5; ++i)
		Move(arr[i]);
	cout << "move end" << '\n';


	int val = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			val = max(val, map2[i][j]);
		}
	}
	
	return val;
}
/*
void BT(int cnt) {
	if(cnt == 5) {

#ifdef DEBUG		
		for(int i=0; i<5; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
#endif
		ans = max(ans, Game());

		return;
	}
	
	
	for(int i=0; i<4; ++i) {
		arr[cnt] = i;
		BT(cnt + 1);
	}

}
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)	cin >> map[i][j];

/*
	if(n == 1) cout << map[0][0];
	else {
		BT(0);
		cout << ans;
	}
*/
	
	Game();


	return 0;
}
