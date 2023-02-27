#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

/*
	s개의 이모티콘을 화면에 만드는 데 걸리는 시간의 최솟값 출력.

	전제조건 
	1. 화면에 이미 1개 입력한 상태 
	2. 다음 3가지 연산을 사용해서 이모티콘을 만들고, 각 연산은 1초 소요. 

		1) 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장.
		2) 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기.
		3) 화면에 있는 이모티콘 중 하나 삭제. 

	3. 클립보드에 이모티콘을 복사하면 이전 클립보드 내용은 덮어쓰기되며,
	클립보드가 비어있는 상태에서는 붙여넣기 불가.
	4. 일부만 클립보드에 복사 및 클립보드의 이모티콘 일부 삭제 불가.
*/

typedef struct {
	int emoticon;
	int clipboard;
	int time;
}state_t;

/* 방문 체크를 2차원배열 혹은 구조체를 사용하여 구현하는 요령이 필요 */
bool check[MAX][MAX];	// emoticon, clipboard

void Bfs(int num) {
	
	queue<state_t> q;
	q.push({1, 0, 0});

	check[1][0] = true;
	
	while(!q.empty()) {
		int x = q.front().emoticon;
		int clip = q.front().clipboard;
		int time = q.front().time;
		
		q.pop();
		
		if(x == num) {
			cout << time;
			break;
		}

		// calculation 1 
		if(x >=0 && x < MAX) {
			if(!check[x][x]) {
				check[x][x] = true;
				q.push({x, x, time + 1});
			}
			
		}

		// calculation 2
		if(clip) {
			int nx = x + clip;
			if(nx < MAX) {			
				if(!check[nx][clip]) {
					check[nx][clip] = true;
					q.push({nx, clip, time + 1});
				}
			}
		}

		// calculation 3
		if(x - 1 >= 0 && x - 1 < MAX) {
			if(!check[x - 1][clip]) {
				check[x - 1][clip] = true;
				q.push({x - 1, clip, time + 1});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s;
	cin >> s;
	Bfs(s);
	
	return 0;
}
