#include <iostream>

using namespace std;

void CalChange(int n) {
	int arr[] = {500, 100, 50, 10, 5, 1};
	int cnt = 0;
	
	for(int i=0; i<6; i++) {
		cnt += n / arr[i];
		n %= arr[i];
	}
	
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	n = 1000 - n;	
	CalChange(n);

	return 0;
}
