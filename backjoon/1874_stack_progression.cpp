#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<char> v;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	stack<int> st;
	
	int sp = 0;
	
	cin >> n;
	while(n--) {
		int t;
		cin >> t;
		
		if(t > sp) {
			
			while(t > sp) {
				sp++;
				st.push(sp);
				v.push_back('+');
			}
			st.pop();
			v.push_back('-');
		}
		else {
			bool flag = false;
			if(!st.empty()) {
				int top = st.top();
				st.pop();
				v.push_back('-');
				
				if(top == t) {
					flag = true;
				}
			}
			if(!flag) {
				cout << "NO";
				return 0;
			}
		}
	}
	
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << '\n';
	}
	
	return 0;
}
