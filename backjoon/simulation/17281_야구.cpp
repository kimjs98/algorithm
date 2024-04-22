#include <algorithm>
#include <iostream>

//#define DEBUG
using namespace std;

int map[50][9];
int seq[9];
bool check[9];
int n, ans;

void Inning() {
	int score = 0;
	int idx = 0;
	
	for(int inn = 0; inn < n; ++inn) {
		bool base[4] = {};
		int out = 0;
		while(out < 3) {
			base[0] = true;
			int go = map[inn][seq[idx++]]; // ??
			if(idx == 9) idx = 0;
			
			if(!go) {
				out++;
				continue;
				
			}
			
			for(int i=3; i>=0; --i) {
				if(!base[i]) continue; // 
				if(i + go >= 4) score++;
				else base[i + go] = true;
				
				base[i] = false;
			}
			
		}
	}
	ans = max(ans, score);
}

void Search(int k) {
	if(k == 9) {
		//Inning();
		
		for(int i=0; i<9; ++i) 
			cout << seq[i] << ' ';
		cout << '\n';

		return;
	}
	
	if(k == 3) {
		Search(k + 1);
		return;
	}
	
	for(int i=1; i<9; ++i) {
		if(check[i]) continue;
		seq[k] = i;
		
		check[i] = true;
		Search(k + 1);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<9; ++j) cin >> map[i][j];

	Search(0);

	return 0;
}







