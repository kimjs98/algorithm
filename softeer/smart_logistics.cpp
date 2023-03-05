#include<iostream>

#define MAX 20001
using namespace std;

/*
	�κ����� ��ġ���� �Ÿ��� K ������ ��ǰ�� ���� �� �ִ�.
	-> �κ��� ��ǰ�� ��ġ�� �־����� �� ��ǰ�� ���� �� �ִ� �κ��� �ִ� ��. 
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
		if(str[i] == 'H')	dy[i + 1] = 1;	// ��ǰ 
		else				dy[i + 1] = 0;	// �κ� 
	}
	
	// ����(���� �ָ��ִ°ź���), ������(���� �������ִ°ź���) �켱������ �����ؼ� ��ǰ ����.
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
