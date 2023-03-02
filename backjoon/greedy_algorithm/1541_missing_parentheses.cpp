#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	
	vector<int> v_num;
	vector<char> v_operator;
	
	string tmp = "";
	for(int i=0; i<str.size() + 1; i++) {
		if(str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			v_num.push_back(stoi(tmp));
			v_operator.push_back(str[i]);
			
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	
	int ans = v_num[0];
	bool minus_flag = false;
	for(int i=0; i<v_operator.size() - 1; i++) {
		if(minus_flag) ans -= v_num[i + 1];
		else {
			if(v_operator[i] == '-') {
				minus_flag = true;
				ans -= v_num[i + 1];
			}
			else	ans += v_num[i + 1];
		}	
	}
	cout << ans;
	return 0;
}
