#include <iostream>
#include <list>
 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	list<char> list;
	
	string str;
	cin >> str;
	
	for(auto c : str) list.push_back(c);
	auto cs = list.end();
	
	int m;
	cin >> m;
	while(m--) {
		char op;
		cin >> op;
		if(op == 'L') {
			if(cs != list.begin()) cs--;
		}
		else if(op == 'D') {
			if(cs != list.end()) cs++;
			
		}
		else if(op == 'B') {
			if(cs != list.begin()) {
				cs--;
				cs = list.erase(cs);
			}
		}
		else {
			char c;
			cin >> c;
			list.insert(cs, c);
			
			
		}
	}
	
	return 0;
} 
