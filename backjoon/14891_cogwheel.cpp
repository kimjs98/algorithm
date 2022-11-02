#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int n, dir;

vector<int> v[5];


void Rotation(int num, int dir) {
	bool temp;
	if(dir == 1) {
		temp = v[num][7];
		v[num].erase(v[num].end() - 1); 
		v[num].insert(v[num].begin(), temp);
	}
	else {
		temp = v[num][0];
		v[num].erase(v[num].begin()); 
		v[num].insert(v[num].end(), temp);
	}
}

void DfsRight(int num, int dir) {
	
	if(num == 4) {
		return;
	}
	else {
	
		if( v[num][2] != v[num + 1][6] ) {
			DfsRight(num + 1, dir * -1);
			Rotation(num + 1, dir * -1);
		}
		else
			return;	
	}
	
}
void DfsLeft(int num, int dir) {
	
	if(num == 1) {
		return;
	}
	else {
	
		if( v[num][6] != v[num - 1][2] ) {
			DfsLeft(num - 1, dir * -1);
			Rotation(num - 1, dir * -1);
		}
		else
			return;	
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	for(int i=1; i<5; i++) {
		cin >> str;
		for(int j=0; j<8; j++) {
			v[i].push_back(str[j] -'0');
		}
	}

	cin >> n;

	int cogwheel, dir;
	for(int i=0; i<n; i++) {
		cin >> cogwheel >> dir;

		if(cogwheel == 1) {
			DfsRight(cogwheel, dir);
			
			Rotation(cogwheel, dir);
		}
		else if(cogwheel == 2) {
			DfsRight(cogwheel, dir);
			DfsLeft(cogwheel, dir);
			
			Rotation(cogwheel, dir);
		}
		else if(cogwheel == 3) {
			DfsRight(cogwheel, dir);
			DfsLeft(cogwheel, dir);
			
			Rotation(cogwheel, dir);
		}
		else {
			DfsLeft(cogwheel, dir);
			
			Rotation(cogwheel, dir);
		}		
	}

	int ans = 0, val = 1;
	for(int i=1; i<5; i++) {
		ans += v[i][0] * val;
		val *= 2;
	}
	cout << ans;

	return 0;
}
