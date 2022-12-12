#include <iostream>

using namespace std;

typedef struct {
	int left;
	int right;
}node;

node node_info[27];

int n;

void PreOrder(int node) {
	if(node < 0) return;
	
	cout << (char)(node + 'A');
	PreOrder(node_info[node].left);
	PreOrder(node_info[node].right);
}
void InOrder(int node) {
	if(node < 0) return;
	
	InOrder(node_info[node].left);
	cout << (char)(node + 'A');
	InOrder(node_info[node].right);

}
void PostOrder(int node) {
	if(node < 0) return;
	
	PostOrder(node_info[node].left);
	PostOrder(node_info[node].right);
	cout << (char)(node + 'A');
}

int main() {
	
	cin >> n;
	for(int i=0; i<n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		
		node -= 'A';
		if(left == '.')	node_info[node].left = -1;
		else			node_info[node].left = left - 'A';
		
		if(right == '.')	node_info[node].right = -1;
		else				node_info[node].right = right -'A';
	}
	
	PreOrder(0);
	cout << '\n';
	InOrder(0);
	cout << '\n';
	PostOrder(0);
	
	return 0;
}
