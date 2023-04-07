/*
	time limit : 2s 
	
	�� �Ǵ� �� ���� ������ �̾��� ��.
	���� ���������� ���̰� ��� ���ų�, ���� �ʿ�
	
	���δ� ���̰� �׻� 1, ���̴� l

	[���� ����]
	
	1. ���δ� ���� ĭ�� ������, 
	L���� ���ӵ� ĭ�� ���� �ٴ��� ��� ���ؾ� ��.

	2. ���� ĭ�� ���� ĭ�� ���̴� 1 ����.

	3. ���θ� ��ġ�� ���� ĭ�� ���̴� ��� ������, l�� ĭ�� ���ӵǾ�� �Ѵ�.
*/

#include <cstring> 
#include <iostream>
#include <vector>

#define endl '\n'
#define MAX 100
using namespace std; 

int n, l;
int map[MAX][MAX];
bool runway[MAX];

int CalRowRoad();
int CalColRoad();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> l;	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}
	
	int road = 0;
	road = CalRowRoad() + CalColRoad();
	cout << road;
	return 0;
}

// l = 2;
int CalRowRoad() {
	int road = 0;
	for(int i=0; i<n; i++) {
		
		bool flag = false;
		int run_cnt = 0;
		memset(runway, false, sizeof(runway));
		for(int j=0; j<n-1; j++) {
			
			if(run_cnt) {
				run_cnt--;
				continue;
			}
			
			int tmp = map[i][j] - map[i][j+1];
			if(tmp == 0) continue; // �� �氣 ��簡 ���� ��� ������ 
			else if(tmp == 1) { // �������� �ϴ� ���� ���� ���
				 
				// j -> �� ��ġ index
				int end = j + l;
				if(end >= n) {
					flag = true;
					break;
				}
				
				// j + 1 = 4, end = 5;
				if(runway[j + 1]) break;
				runway[j + 1] = true;
				
				for(int k=j+1; k<end; k++) {
					if(map[i][k] == map[i][k + 1]) {
						runway[k + 1] = true;
						
					}
					else {
						flag = true;
						break;
					}
				}
				
				if(flag) break;
				run_cnt = l - 1;
			}
			else if(tmp == -1) { // �������� �ϴ� ���� ���� ���
				
				// j -> �� ��ġ index
				int start = j - l + 1; 
				if(start < 0 ) {
					flag = true;
					break;
				}
				// ���� ��ġ 
				if(runway[j]) {
					flag = true;
					break;	
				}
				runway[j] = true; // �� ��ġ ���� ��ġ

				for(int k=j; k>start; k--) {
					if(map[i][k] == map[i][k - 1]) {
						if(runway[k-1]) {
							flag = true;
							break;
						}
						else {
							runway[k-1] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			else {	// ���� ���̰� 1���� ū ���  
				flag = true;
				break;				
			}
		}
		
		if(!flag) {
			//cout << "complete num : " << i << endl;
			road++;
		}
		
		/*
		for(int j=0; j<n; j++)
			cout << runway[j] << ' ';
		cout << endl;
		*/ 
	}
	
	return road;
}
int CalColRoad() {	
	int road = 0;
	for(int i=0; i<n; i++) {
		
		bool flag = false;
		int run_cnt = 0;
		memset(runway, false, sizeof(runway));
		for(int j=0; j<n-1; j++) {
			
			if(run_cnt) {
				run_cnt--;
				continue;
			}
			
			int tmp = map[j][i] - map[j+1][i];
			if(tmp == 0) continue; // �� �氣 ��簡 ���� ��� ������ 
			else if(tmp == 1) { // �������� �ϴ� ���� ���� ���
				 
				// j -> �� ��ġ index
				int end = j + l;
				if(end >= n) {
					flag = true;
					break;
				}
				
				// j + 1 = 4, end = 5;
				if(runway[j + 1]) break;
				runway[j + 1] = true;
				
				for(int k=j+1; k<end; k++) {
					if(map[k][i] == map[k + 1][i]) {
						runway[k + 1] = true;
						
					}
					else {
						flag = true;
						break;
					}
				}
				
				if(flag) break;
				run_cnt = l - 1;
			}
			else if(tmp == -1) { // �������� �ϴ� ���� ���� ���
				
				// j -> �� ��ġ index
				int start = j - l + 1; 
				if(start < 0 ) {
					flag = true;
					break;
				}
				// ���� ��ġ 
				if(runway[j]) {
					flag = true;
					break;	
				}
				runway[j] = true; // �� ��ġ ���� ��ġ

				for(int k=j; k>start; k--) {
					if(map[k][i] == map[k - 1][i]) {
						if(runway[k-1]) {
							flag = true;
							break;
						}
						else {
							runway[k-1] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			else {	// ���� ���̰� 1���� ū ���  
				flag = true;
				break;				
			}
		}
		
		if(!flag) {
			//cout << "complete num : " << i << endl;
			road++;
		}
		
		/*
		for(int j=0; j<n; j++)
			cout << runway[j] << ' ';
		cout << endl;
		*/ 
	}
	
	return road;
}
