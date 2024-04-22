#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	vector<int> v_section, v_check;
	
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		for(int j=0; j<a; ++j)
			v_section.push_back(b);
	}
	
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		for(int j=0; j<a; ++j)
			v_check.push_back(b);
	}

	int ans = 0;
	for(int i=0; i<v_section.size(); ++i) {
		ans = max(ans, v_check[i] - v_section[i]);
	}
	cout << ans;

	return 0;
}
