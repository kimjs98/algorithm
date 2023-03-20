#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int document;
	int interview;
}state_t;

struct cmp {
	bool operator()(state_t a, state_t b) {
		return a.document > b.document;
	}		
};

void CalMaxMember();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		CalMaxMember();
	}
		
	return 0;
}

void CalMaxMember() {	
	priority_queue<state_t, vector<state_t>, cmp> pq;
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({a, b});
	}

	int cnt = 0;
	int minval = n+1;
	while(!pq.empty()) {
		int document = pq.top().document;
		int interview = pq.top().interview;
		pq.pop();

		if(interview < minval) {
			cout << document << ' ' << interview << '\n';
			
			cnt++;
			minval = interview;
		}
	}
	
	cout << cnt << '\n';
}
