#include <algorithm>
#include <cstring> 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//#define DEBUG
#define MAX 401

typedef struct {
	int max_favorite;
	int max_empty;
}point;

point map_info[MAX][MAX];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int cal[] = {0, 1, 10, 100, 1000};

int n;

typedef struct {
	int num;
	int favorite_num[4];
}student;
vector<student> student_num;

student map[MAX][MAX];

typedef struct {
	int y, x;
	
}yx;
queue<yx> q;
queue<yx> q_step;

void SetPosition(student *idx);
void CalSatisFaction();

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	/* input */
	cin >> n;
	for(int i=0; i<n*n; i++) {
		int idx0, idx1, idx2, idx3, idx4;
		cin >> idx0 >> idx1 >> idx2 >> idx3 >> idx4;
		student_num.push_back({idx0, {idx1, idx2, idx3, idx4}});
	}	

	/* solution */
	for(int i=0; i<student_num.size(); i++) {
		SetPosition(&student_num[i]);
	}	

	CalSatisFaction();
	
#ifdef DEBUG
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << map[i][j].num << ' ';
		}
		cout << '\n';
	} 
#endif

	return 0;
}

void SetPosition(student *idx) {
	
#ifdef DEBUG
	cout << "num : " << idx->num << " favorite_num : ";
	for(int i=0; i<4; i++) {
		cout << idx->favorite_num[i] << ' ';
	}
	cout << '\n';
#endif

	/* init */
	memset(map_info, false, sizeof(map_info));
	int max_favorite = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			
			if(map[i][j].num)	continue;

			/* 비어있는 칸(i, j)에서 인접한 칸에 좋아하는 학생 수 탐색 */			
			for(int k=0; k<4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				if(ny>=0 && nx>=0 && ny<n && nx<n) {
					int temp = map[ny][nx].num;
					
					/* 인접하는 칸에 좋아하는 학생이 있는 경우 */
					if(temp == idx->favorite_num[0] || temp == idx->favorite_num[1] ||
						temp == idx->favorite_num[2] || temp == idx->favorite_num[3]) {

						map_info[i][j].max_favorite++; 
					}
					else if(temp == 0) {
						map_info[i][j].max_empty++;
					}
					else;
				}
			}
			
			max_favorite = max(max_favorite, map_info[i][j].max_favorite);
		}
	}
	
	int max_empty = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {

			if(map[i][j].num)	continue;

			/* 1을 만족하는 칸 q에 push */
			if(map_info[i][j].max_favorite == max_favorite) {
				q.push({i, j});
				max_empty = max(max_empty, map_info[i][j].max_empty);

#ifdef DEBUG
				cout << "yx :" << i << j << " max_empty : " << map_info[i][j].max_empty << " max : " << max_empty <<'\n';	
#endif
			}
		}
	}

	bool flag = false;
	while(!q.empty()) {
		
		/* 1을 만족하는 여러 칸 */
		int y = q.front().y;
		int x = q.front().x;

		if(q.size() == 1 && flag == false) {
			map[y][x].num = idx->num;
			for(int i=0; i<4; i++) {
				map[y][x].favorite_num[i] = idx->favorite_num[i];
			}
			
#ifdef DEBUG
			cout << "step 1 : " <<"yx :" << y << x << " num : " << idx->num << '\n';	
#endif	
		}
		else {
			flag = true;
			/* 2를 만족하는 칸 */
			if(map_info[y][x].max_empty == max_empty) {
				map[y][x].num = idx->num;
				for(int i=0; i<4; i++) {
					map[y][x].favorite_num[i] = idx->favorite_num[i];
				}
#ifdef DEBUG
				cout << "step 2 : " << "yx :" << y << x << " num : " << idx->num << '\n';	
#endif					
				while(!q.empty()) q.pop();
				break;
			} 
		}
		q.pop();
	}
}

void CalSatisFaction() {
	
	int ans = 0, cnt = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {

			for(int k=0; k<4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny>=0 && nx>=0 && ny<n && nx<n) {
					int temp = map[ny][nx].num;

					/* 인접하는 칸에 좋아하는 학생이 있는 경우 */
					if(temp == map[i][j].favorite_num[0] || temp == map[i][j].favorite_num[1] ||
						temp == map[i][j].favorite_num[2] || temp == map[i][j].favorite_num[3]) {

						cnt++;
					}
				}
			}

			ans = ans + cal[cnt];
			cnt = 0;			
		}
	}
	cout << ans << '\n';
}

