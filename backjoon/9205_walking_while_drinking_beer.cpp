#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int y, x;
	int step;
}pos_t;
queue<pos_t> q;

typedef struct {
	int y, x;
	bool state;
}state_t;
vector<state_t> v;

bool Bfs(int festival_y, int festival_x) {
	
	while(!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int step = q.front().step;

		q.pop();
		
		int dist = abs(y - festival_y) + abs(x - festival_x); 
		if(dist > 1000 + step) {
			for(int i=0; i<v.size(); i++) {
			
				int ny = v[i].y;
				int nx = v[i].x;
				
				dist = abs(y - ny) + abs(x - nx);
				if(dist <= 1000 + step && !v[i].state) {
					step = dist % 50;
					q.push({ny, nx, step});
					v[i].state = true;
				}
			}
		}
		else {
			while(!q.empty())	q.pop();
				
			return true;	
		}	
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	while(testcase--) {
		
		int n;
		cin >> n;
		
		int x, y;
		cin >> x >> y;
		q.push({y, x, 0});	// home
		
		/* store */ 
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			v.push_back({y, x, false});	
		}

		cin >> x >> y;	// festival
		
		bool ret = Bfs(y, x);
		if(ret)	cout << "happy" << '\n';
		else	cout << "sad" << '\n';
		
		v.clear();
	}
	
	return 0;
}
