#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int k;
char sign[10];
bool check[10];

vector<string> ans; 

bool checking(string num)
{
	for(int i=0; i<k; i++)
	{
		if( sign[i] == '<')
		{
			if(num[i] > num[i+1])
				return false;
		}
		else if( sign[i] == '>')
		{
			if(num[i] < num[i+1])
				return false;
		}		
	}
	return true;
}

void dfs(int index, string num)
{
	if(index == k+1)
	{
		if(checking(num))
			ans.push_back(num);
			
		return;
	}
	
	for(int i=0; i<=9; i++)
	{
		if(check[i]) continue;
		check[i] = true;
		dfs(index+1, num + to_string(i));
		check[i] = false;
	
	}
	
}

int main()
{	
	cin >> k;
	for( int i=0; i<k; i++ )
	{
		cin >> sign[i];
	}
	dfs(0,"");
	
	cout << *max_element(ans.begin(), ans.end()) << '\n';
	cout << *min_element(ans.begin(), ans.end());	
		
	return 0;
}
