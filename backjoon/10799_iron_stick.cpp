#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char> st;
	int stick = 0, ans = 0;

	string iron_stick;
	cin >> iron_stick;
	
	for(auto index : iron_stick) {
		
		if(index == '(') {
			if(!st.empty()) {
				if(st.top() == '(')	stick++;	
			}
	
			st.push(index);		
		}
		else {
			
			if(st.top() == ')') {	// stick 
				stick--;
				ans++;
			}
			else {					// laser
				ans = ans + stick;
			}
			
			st.push(index);
		}
	}	
	cout << ans; 
	
	return 0;
}
