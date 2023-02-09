#include <iostream>
#include <vector>

#define MAX 50
using namespace std;

int parent_node[MAX];
bool check[MAX];
vector<int> v[MAX];

int n, ans, delete_node, root_node;

void Dfs(int node) {
//	cout << node << ' ';
	check[node] = true;
	
	if(v[node].empty()) ans++;
	else {
		
		bool flag = false;
		for(int i=0; i<v[node].size(); i++) {
			int next = v[node][i];
			if(!check[next]) {

				if(next == delete_node) {
					flag = true; 
					continue;	
				}
				
				Dfs(next);
			}
		}
		
		/*	단일 노드인 경우 자식 노드가 삭제되면 부모 노드가 리프 노드가 되므로 이를 고려해야 한다.*/
		if(flag) {
				if(v[node].size() == 1)	ans++;
		}
	}	
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for(int i=0; i<n; i++) {
		int node;
		cin >> node;
		if(node == -1) {
			root_node = i;
			continue;
		}

		//v[i].push_back(node);
		v[node].push_back(i);
	}
	cin >> delete_node;

	if(root_node == delete_node) cout << 0;
	else {
		Dfs(root_node);
		cout << ans;		
	}

	return 0;
}
