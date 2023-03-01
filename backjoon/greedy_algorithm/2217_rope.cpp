#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> v;
	for(int i=0; i<n; i++) {
		int w;
		cin >> w;
		v.push_back(w);
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i=0; i<v.size(); i++) {
		int tmp = v[i] * (n - i);
		ans = max(ans, tmp);
	}
	cout << ans;
	
	return 0;
}
