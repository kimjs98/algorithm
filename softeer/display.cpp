#include<iostream>

using namespace std;

/*
	 1
	2 3
	 4
	5 6
	 7
*/

int arr[10][8] = {
	//{0, 1, 2, 3, 4, 5, 6, 7}, // 0
	{0, 1, 1, 1, 0, 1, 1, 1}, // 0
	{0, 0, 0, 1, 0, 0, 1, 0}, // 1
	{0, 1, 0, 1, 1, 1, 0, 1}, // 2
	{0, 1, 0, 1, 1, 0, 1, 1}, // 3
	{0, 0, 1, 1, 1, 0, 1, 0}, // 4
	{0, 1, 1, 0, 1, 0, 1, 1}, // 5
	{0, 1, 1, 0, 1, 1, 1, 1}, // 6
	{0, 1, 1, 1, 0, 0, 1, 0}, // 7
	{0, 1, 1, 1, 1, 1, 1, 1}, // 8
	{0, 1, 1, 1, 1, 0, 1, 1}, // 9
};

int initnum[] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6}; 
 
void Cal(int a, int b) {

	int cnt = 0;	 
	while(a > 0 || b > 0) {

		int tmp = b % 10;		
		int tmp2 = a % 10;

		//cout << tmp << '\n';
		
		
		if(a <= 0) {
			cnt += initnum[tmp];
		}
		else if(b <= 0) {
			cnt += initnum[tmp2];
		}
		else {
			for(int i = 1; i < 8; ++i) {	
				if(arr[tmp][i] && !arr[tmp2][i])	cnt++;
				else if(!arr[tmp][i] && arr[tmp2][i]) cnt++;
				else;		
			}		
		}
		//cout << cnt << ' ';
		
		b /= 10;
		a /= 10;
		
	}

	cout << cnt << '\n';
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int testcase;
	cin >> testcase;
	while(testcase--) {
		int a, b;
		cin >> a >> b;

		Cal(a, b);
	}

	return 0;
}
