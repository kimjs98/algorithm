/*
	time limit : 2s 
	
	행 또는 열 끝과 끝으로 이어진 길.
	길을 지나가려면 높이가 모두 같거나, 경사로 필요
	
	경사로는 높이가 항상 1, 길이는 l

	[경사로 조건]
	
	1. 경사로는 낮은 칸에 놓으며, 
	L개의 연속된 칸에 경사로 바닥이 모두 접해야 함.

	2. 낮은 칸과 높은 칸의 높이는 1 고정.

	3. 경사로를 배치할 낮은 칸의 높이는 모두 같으며, l개 칸에 연속되어야 한다.
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
			if(tmp == 0) continue; // 두 길간 경사가 같은 경우 지나감 
			else if(tmp == 1) { // 지나가야 하는 길이 낮은 경우
				 
				// j -> 현 위치 index
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
			else if(tmp == -1) { // 지나가야 하는 길이 높은 경우
				
				// j -> 현 위치 index
				int start = j - l + 1; 
				if(start < 0 ) {
					flag = true;
					break;
				}
				// 경사로 설치 
				if(runway[j]) {
					flag = true;
					break;	
				}
				runway[j] = true; // 현 위치 경사로 설치

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
			else {	// 높이 차이가 1보다 큰 경우  
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
			if(tmp == 0) continue; // 두 길간 경사가 같은 경우 지나감 
			else if(tmp == 1) { // 지나가야 하는 길이 낮은 경우
				 
				// j -> 현 위치 index
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
			else if(tmp == -1) { // 지나가야 하는 길이 높은 경우
				
				// j -> 현 위치 index
				int start = j - l + 1; 
				if(start < 0 ) {
					flag = true;
					break;
				}
				// 경사로 설치 
				if(runway[j]) {
					flag = true;
					break;	
				}
				runway[j] = true; // 현 위치 경사로 설치

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
			else {	// 높이 차이가 1보다 큰 경우  
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
