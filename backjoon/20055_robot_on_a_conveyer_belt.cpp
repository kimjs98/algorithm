#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

int n, k;
int cnt;

vector<bool> robot;
vector<int> belt;

void MoveBelt() {
	int temp;
	
	temp = belt.back();
	belt.erase(belt.end() - 1);
	belt.insert(belt.begin(), temp);
	
	temp = robot.back();
	robot.erase(robot.end() - 1);
	robot.insert(robot.begin(), temp); 
	
	if(robot[n-1] == 1)	robot[n-1] = 0; 
}

void MoveRobot() {
	for(int i=n-2; i>=0; i--) {
		
		if(robot[i] && robot[i+1] == 0) {
			if(belt[i+1] > 0) {
				
				robot[i] = 0;
				if((--belt[i+1]) == 0)	cnt++;
				
				if(i == n-2)	continue;
				robot[i+1] = 1;	
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	int input;
	for(int i=0; i<2*n; i++) {
		cin >> input;
		belt.push_back(input);
		robot.push_back(0);
	}

	int ans = 0;
	while(1) {
		ans++;

		/* step 1 */
		MoveBelt();

		/* step 2 */
		MoveRobot();

		/* step 3 */
		if(belt[0] > 0) {
			robot[0] = 1;
			if((--belt[0]) == 0)	cnt++;
		}

		/* step 4 */
		if(cnt >= k)
			break;
	}
	cout << ans;

	return 0;
}
