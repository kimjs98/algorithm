#include <iostream>
#include <queue>
#include <vector>

//#define DEBUG
using namespace std;
const int MAX = 101;

int n, w, l;	// n : 트럭 개수, w : 다리 길이, l : 다리 최대 하중 
int bridge[MAX];

int CheckWei() {

}

void Move() {
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> w >> l;
	queue<int> q;	 
	for(int i=1; i<=n; ++i) {
		int num;
		cin >> num;
		q.push(num);
	}
		
#ifdef DEBUG

#endif

	return 0;
}







