#include <iostream>
#include <stack>

using namespace std;

typedef struct {
	int h, idx;
}top_t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	stack<top_t> s;
	s.push({100000001, 0});
	
	for(int i=1; i<=n; ++i) {
		int h;
		cin >> h;
		
		while(s.top().h < h) {
			cout << s.top().h << ' ';
			s.pop();
		}
		cout << '\n';
		
		cout << s.top().idx << ' ';
		s.push({h, i});
	}
	
	
	
	return 0;
}
