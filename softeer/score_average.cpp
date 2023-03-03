#include<iostream>
#include<cmath>

#define MAX 1000001
using namespace std;

int s[MAX];
int sum[MAX];

double Round(double num) {
	num *= 100;
	num = round(num);
	num /= 100;

	return num;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<n+1; i++) {
		cin >> s[i];
	}

	sum[1] = s[1];
	for(int i=2; i<n+1; i++) {
		sum[i] = s[i] + sum[i - 1];
	}

	for(int i=0; i<k; i++) {
		int a, b;
		cin >> a >> b;
	
		double ret = (double)(sum[b] - sum[a - 1]) / (double)((b - a) + 1);
		ret = Round(ret);
		//cout << ret << '\n';
		printf("%.2f\n", ret);
	}

	return 0;
}
