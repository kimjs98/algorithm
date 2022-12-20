#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int priority;
	int num;
}queue_t;

void PrinterQueue(int num, int document) {

	queue<queue_t> q;
	priority_queue<int> pq;
	
	for(int i=0; i<num; i++) {
		int tmp;
		cin >> tmp;
		q.push({tmp, i});
		pq.push(tmp);
	}
	
	int cnt = 0;
	while(!q.empty()) {

		int priority = q.front().priority;
		int num = q.front().num;
		q.pop();
		
		if(pq.top() == priority) {
			pq.pop();
			cnt++;
			
			if(num == document) {
				cout << cnt << '\n';
				break;
			}
		}
		else {
			q.push({priority, num});
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	
	while(testcase--) {
		int n, m;
		cin >> n >> m;
		PrinterQueue(n, m);			
	}

	return 0;
}

