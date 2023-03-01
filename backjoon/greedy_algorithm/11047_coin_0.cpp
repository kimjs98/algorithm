#include <iostream>

#define MAX 10
using namespace std;

int arr[MAX];

void CalChange(int num, int sum) {
	int cnt = 0;
	for(int i=num-1; i>=0; i--) {
		cnt += sum / arr[i];
		sum %= arr[i];
	}
	
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	CalChange(n, k);
	
	return 0;
}
