#include<iostream>

#define MAX 20001
using namespace std;

/*
	로봇들의 위치에서 거리가 K 이하인 부품만 잡을 수 있다.
	-> 로봇과 부품의 위치가 주어졌을 때 부품을 집을 수 있는 로봇의 최대 수. 
*/
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	string str;
	int dy[n + 1] = { 0, };
	bool check[n + 1] = { 0, };
	 
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == 'H')	dy[i + 1] = 1;	// 부품 
		else				dy[i + 1] = 0;	// 로봇 
	}
	
	// 왼쪽(가장 멀리있는거부터), 오른쪽(가장 가까이있는거부터) 우선순위로 선택해서 부품 수집.
	int cnt = 0;
	for(int i=1; i<n + 1; i++) {
		if(dy[i]) {
			bool flag = false;
			for(int j=i-k; j<i; j++) {
				if((j > 0) && !dy[j]) {
						if(check[j])	continue;
						
						flag = true;
						check[j] = true;
						
						cnt++;
						break;					
				}
			}
			
			if(!flag) {
				for(int j = i + 1; j<= i + k; j++) {
					if((j < n + 1) && !dy[j])  {
						if(check[j])	continue;
						check[j] = true;
						cnt++;
						break;
					}
				}
			}
		}
	}
	
	cout << cnt;
	return 0;
}
