#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 11

int n;
int arr[MAX];
vector<int> opt;

int min_val = 2147000000, max_val = -2147000000;
void Dfs(int index, int sum) {

	if(index == opt.size()) {

		min_val = min(min_val, sum);
		max_val = max(max_val, sum);

		return;
	}
	
	if(opt[index] == 0) {
		Dfs(index + 1, sum + arr[index + 1]);
	}
	else if(opt[index] == 1) {
		Dfs(index + 1, sum - arr[index + 1]);
	}
	else if(opt[index] == 2) {
			Dfs(index + 1, sum * arr[index + 1]);
	}	
	else if(opt[index] == 3) {
		if(sum < 0) {
			Dfs(index + 1, ((sum * -1) / arr[index + 1]) * -1 );
		}
		else
			Dfs(index + 1, sum / arr[index + 1]);
	}
	else;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	
	int i,j;
	for(i=0; i<n; i++) {
		cin >> arr[i];
	}

	int num;
	for(i=0; i<4; i++) {
		cin >> num;
		for(j=0; j<num; j++) {
			opt.push_back(i);
		}
	}
	
	do {	
		Dfs(0, arr[0]);		
	} while (next_permutation(opt.begin(), opt.end()));
	
	cout << max_val << '\n';
	cout << min_val;
	
	return 0;
}
