#include <iostream>
#include <stack>
#include <queue>

//#define DEBUG
#define MAX 100001
using namespace std;

int pre_node[MAX];
int pos[MAX];
bool visit[MAX];

int n, k;

void Bfs(){
	queue<int> q;
	
	q.push(n);
	visit[n] = true;

	int x = n;
	while(x != k) {
		
		x = q.front();	
		q.pop();
		
		int arr[] = { -1, 1, x};
		for(int i=0; i<3; i++) {
			int nx = x + arr[i];
			if(nx > -1 && nx < MAX) {
				if(!visit[nx]) {
					q.push(nx);
					visit[nx] = true;
					
					pre_node[nx] = x; 
					pos[nx] = pos[x] + 1;
				}
			}
		}
	}
	cout << pos[k] << '\n';
	
	stack<int> st;
	int node = k;

	while(node) {
		st.push(node);	
		node = pre_node[node];
	}

	if(n == 0)	cout << 0 << ' ';	// n = 0부터 시작한 경우에 대한 에러처리 
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

#ifdef DEBUG
	for(int i=0; i<=k; i++) {
		cout << pre_node[i] << ' ';
	}
	cout << '\n';
#endif
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> k;
	
	if(n > k) {
		cout << n - k << '\n';
		for(int i=n; i>=k; i--) {
			cout << i << ' ';
		}	
	}
	else if(n == k)	cout << 0 << '\n' << n;
	else 			Bfs();
	
	return 0;
}
