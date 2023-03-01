#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 11
using namespace std;

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i=1; i<=n; i++) {
		int x;	// i���� Ű�� ū ����� ���ʿ� ��� �־����� ��Ÿ���� �� 
		cin >> x;
		
		int cnt = 0;
		for(int j=1; j<=n; j++) {
			if(cnt == x && !arr[j]) {
				arr[j] = i;
				break;
			}
			
			if(!arr[j]) cnt++;
		}
	}
		
	for(int i=1; i<=n; i++)
		cout << arr[i] << ' ';

	return 0;
}
