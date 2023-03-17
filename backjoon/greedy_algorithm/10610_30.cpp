#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	cin >> str;
	int arr[str.length()] = {0, };
	
	int sum = 0;
	bool flag = false;
	for(int i=0; i<str.length(); i++) {
		arr[i] = str[i] - '0';
		sum += arr[i];
		if(arr[i] == 0)	flag = true;
	}	
 
	if(flag && sum % 3 == 0) {
		sort(arr, arr + str.length(), cmp);
		for(int i=0; i<str.length(); i++) {
			cout << arr[i];
		}
	}
	else	cout << -1;

	return 0;
}
