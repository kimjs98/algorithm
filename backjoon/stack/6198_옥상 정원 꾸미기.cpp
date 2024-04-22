#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	stack<int> s;
	int h;
	cin >> h;
	s.push(h); // 첫번째 값 stack에 push 
	
	unsigned long long ans = 0;
	for(int i=2; i<=n; ++i) {
		cin >> h;
		
		while(!s.empty() && s.top() <= h)
			s.pop();
			
		//cout << s.size() << ' ';
		ans += s.size();
		s.push(h);
	}
	cout << ans;

	return 0;
}
