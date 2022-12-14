#include <iostream>
#include <string>

#define MAX 64

using namespace std;

int n;
bool map[MAX][MAX];

void QuadTree(int y, int x, int size) {
	
	for (int i=0; i< size; i++) {
		for(int j=0; j< size; j++) {
			if(map[i + y][j + x] != map[y][x]) {
				int half = size / 2;
				
				cout << "(";
				QuadTree(y, x, half);
				QuadTree(y, x + half, half);
				QuadTree(y + half, x, half);
				QuadTree(y + half, x + half, half);
				cout << ")";
				
				return;
			}
					
		}
	}
	
	cout << map[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;	
	
	string str;
	for (int i=0; i<n; i++) {
		cin >> str;
		for(int j=0; j<n; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	
	QuadTree(0, 0, n);
	
	return 0;
}
