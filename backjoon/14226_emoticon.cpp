#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

/*
	s���� �̸�Ƽ���� ȭ�鿡 ����� �� �ɸ��� �ð��� �ּڰ� ���.

	�������� 
	1. ȭ�鿡 �̹� 1�� �Է��� ���� 
	2. ���� 3���� ������ ����ؼ� �̸�Ƽ���� �����, �� ������ 1�� �ҿ�. 

		1) ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 ����.
		2) Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ�.
		3) ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ� ����. 

	3. Ŭ�����忡 �̸�Ƽ���� �����ϸ� ���� Ŭ������ ������ �����Ǹ�,
	Ŭ�����尡 ����ִ� ���¿����� �ٿ��ֱ� �Ұ�.
	4. �Ϻθ� Ŭ�����忡 ���� �� Ŭ�������� �̸�Ƽ�� �Ϻ� ���� �Ұ�.
*/

typedef struct {
	int emoticon;
	int clipboard;
	int time;
}state_t;

/* �湮 üũ�� 2�����迭 Ȥ�� ����ü�� ����Ͽ� �����ϴ� ����� �ʿ� */
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
