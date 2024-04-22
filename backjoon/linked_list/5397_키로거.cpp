#include <iostream>
#include <list>
 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--) {
		string str;
		cin >> str;
		
		list<char> list;
		auto cs = list.begin();
		
		for(auto c : str) {
			if(c == '-') {
				if(cs != list.begin()) {
					cs--;
					cs = list.erase(cs);
				}		
			}
			else if(c == '<') {
				if(cs != list.begin()) cs--;
			}
			else if(c == '>') {
				if(cs != list.end()) cs++;
			}
			else {
				list.insert(cs, c);
			}
		}
		
		for(auto c : list) cout << c;	
		cout << '\n';
	}
	
	
	return 0;
} 
