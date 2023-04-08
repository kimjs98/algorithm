#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, b, c;
	cin >> n;
	
	int arr[n + 1] = {0, }; 
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	
	long long supervisor = 0;
	for(int i=1; i<=n; i++) {
		int num = arr[i] - b;
		supervisor++;
		if(num > 0) {
			
			int tmp = num / c;
			if(num % c == 0) {
				supervisor += tmp;
			}
			else {
				supervisor += tmp + 1;
			}
			
		}
	}
	cout << supervisor;
	
	return 0;	
}
