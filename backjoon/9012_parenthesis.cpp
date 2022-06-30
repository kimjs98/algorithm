#include <iostream>
#include <stack>
#include <string>

using namespace std;

void check_vps() {
	bool flag = true;
	string str;
	cin >> str;
	
	stack<char> s; 
	for(auto i: str) {
		
		if( i == '(' ) {
			s.push(i);
		}
		else {
			
			if(!s.empty())
			{
				s.pop();
			}
			else {
				flag = false;
				break;
			}				
		}		
	}
	
	if(!s.empty() || !flag){
		cout << "NO" << '\n';
	}
	else
		cout << "YES" << '\n';
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int testcase;
	cin >> testcase;
	
	while(testcase--)
	{
		check_vps();
	}
}
