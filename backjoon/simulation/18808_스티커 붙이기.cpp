#include <algorithm>
#include <iostream>
#include <vector>

//#define DEBUG
// time limit : 2s / 512 MB / n, m <= 8
using namespace std;

const int MAX = 40;
int n, m, k, cnt;

typedef struct {
	int y, x;
}pos_t;
vector<pos_t> v;

bool note[MAX][MAX];
bool sticker[10][10][100];
bool tmp[10][10];

void Rotate(int y, int x, int num) {

	for(int i=0; i<y; ++i) 
		for(int j=0; j<x; ++j) tmp[i][j] = sticker[i][j][num];
	
	int r = 0; 
	int c = 0;

	for(int i=0; i<x; ++i) {
		r = y - 1;
		for(int j=0; j<y; ++j) {
			sticker[i][j][num] = tmp[r--][c];
		}
		c++;
	}
	
	// swap
	v[num].y = x;
	v[num].x = y;
}
bool CheckSticker(int y, int x, int num) {

#ifdef DEBUG	
	cout << "check sticker" << '\n';
	for(int i=y; i<y + v[num].y; ++i) {
		for(int j=x; j<x + v[num].x; ++j) {
			cout << sticker[i - y][j - x][num] << ' ';
		}
		cout << '\n';
	}
#endif
	for(int i=y; i<y + v[num].y; ++i) {
		for(int j=x; j<x + v[num].x; ++j) {
			
			// ?
			if(note[i][j] && sticker[i - y][j - x][num])
				return false;
		}
	}
	
	for(int i=y; i<y + v[num].y; ++i) {
		for(int j=x; j<x + v[num].x; ++j) {
			if(sticker[i - y][j - x][num]) {
				note[i][j] = sticker[i - y][j - x][num];
				cnt++;			
			}

		}

	}

#ifdef DEBUG	
	cout << "note : " << num << '\n';
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cout << note[i][j] << ' ';
		}
		cout << '\n';
	}
#endif
	return true;
}
bool CheckNote(int num) {	
	// n, m
	if(v[num].y > n || v[num].x > m) return false;
	
	for(int i=0; i<=n-v[num].y; ++i) {
		for(int j=0; j<=m-v[num].x; ++j) {

			if(CheckSticker(i, j, num))
				return true;
		}
	}

	return false;
}

void Simulation() {

	// i : 스티커 번호 v : 스티커 사이즈 
	for(int i=0; i<v.size(); ++i) {
		
		for(int j=0; j<4; ++j) {
			
#ifdef DEBUG
			cout << "rotate " << j << '\n';
			for(int a=0; a<v[i].y; ++a) {
				for(int b=0; b<v[i].x; ++b) {
					cout << sticker[a][b][i] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
#endif
			bool ret = CheckNote(i);
			if(ret || j == 3) break;
			else Rotate(v[i].y, v[i].x, i);
		}
	}
	
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k; 
	for(int i=0; i<k; ++i) {
		int r, c;
		cin >> r >> c;
		
		v.push_back({r, c});
		for(int a=0; a<r; ++a)
			for(int b=0; b<c; ++b) cin >> sticker[a][b][i];
	}

	Simulation();
		
	return 0;
}
