#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int arr[n + 1] = { 0, };	
	for(int i=0; i<n; i++) {
		cin >> arr[i];		
	}
	sort(arr, arr + n);
	
	return 0;
}
