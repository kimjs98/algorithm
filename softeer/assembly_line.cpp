#include <algorithm>
#include <iostream>

#define A 	0
#define B 	1
#define MAX 1001
using namespace std;

typedef struct {
	int a;
	int b;
	int move_a;
	int move_b;
}move_t;

int n;
move_t arr[MAX];
int workspace[2][MAX];

void Calmintime(int num) {
	workspace[A][1] = arr[1].a;
	workspace[B][1] = arr[1].b;

	for(int i=2; i<=num; i++) {
		workspace[A][i] = arr[i].a + min(workspace[A][i - 1], workspace[B][i - 1] + arr[i - 1].move_a);
		workspace[B][i] = arr[i].b + min(workspace[B][i - 1], workspace[A][i - 1] + arr[i - 1].move_b);
	}
	
	cout << min(workspace[A][num], workspace[B][num]); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=1; i<n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].move_b >> arr[i].move_a;		
	}
	cin >> arr[n].a >> arr[n].b;
	
	Calmintime(n);

	return 0;
}
