#include <algorithm>
#include <iostream>

using namespace std;
using ull = unsigned long long;

// ���������� -> �ͳ����� ���. base condition�� �� �����ϰ� 
// k���� ����� ���� 2k, 2k + 1�� ����� ����ϴ� ���� �����  

ull Pow(ull a, ull b, ull c) {
	//cout << b << '\n'; // 11 5 2 1
	
	if(b == 1) return a % c;	// base condition
	ull val = Pow(a, b/2, c);
	//cout << "val : " << val << '\n';
	val = val * val % c;

	// return 
	if(b % 2 == 0) return val;
	return val * a % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ull a, b, c;
	cin >> a >> b >> c;

	ull ans = Pow(a, b, c); 
	
	return 0;
}
