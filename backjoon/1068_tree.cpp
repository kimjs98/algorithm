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
		
		/*	���� ����� ��� �ڽ� ��尡 �����Ǹ� �θ� ��尡 ���� ��尡 �ǹǷ� �̸� ����ؾ� �Ѵ�.*/
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
