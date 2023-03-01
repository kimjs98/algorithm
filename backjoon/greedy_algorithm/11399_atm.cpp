#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	vector<int> v;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> p;
		v.push_back(p);		
	}
	
	sort(v.begin(), v.end());
	
	int sum = 0;
	for(int i=0; i<v.size(); i++) {
		sum += v[i] * (n - i);
	}
	cout << sum;
	
	return 0;
}
