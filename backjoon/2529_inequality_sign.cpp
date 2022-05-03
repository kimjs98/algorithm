#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int k;
char arr[10];
bool check[10];
vector<string> max(10), min(10);

vector<string> ans; 

bool check_cond(string num)
{
	for(int i=0; i<k; i++)
	{
		if(arr[i] == '<')
		{
			if(num[i] > num[i+1])
				return false;
		}
		else if( arr[i] == '>')
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
		if(check_cond(num))
			ans.push_back(num);
			
		return;
	}
	
	for(int i=0; i<9; i++)
	{
		if(check[i]) continue;
		
		check[i] = true;
		dfs(index+1, arr + to_string(i));
		check[i] = false;
	
	}
	
}

int main()
{	
	cin >> k;
	for( int i=0; i<k; i++ )
	{
		cin >> arr[i];
	}
	
	dfs(0,"");
	

	return 0;
}
