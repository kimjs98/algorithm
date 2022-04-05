#include <iostream>
using namespace std;

int ans[9];
bool decide[9];
int index;

//#define SEQUENCE
#define SELECT

#ifdef SEQUENCE
void sequence(int index, int started, int n, int m)
{
	if( index == m)
	{
		for( int i=0; i<m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		
		return;	
	}
	
	// sequence(0, 1, n, m);
	
	for( int i=started; i<=n; i++ )		
	{
		if(decide[i])
			continue;
		
		decide[i]= true;	
		ans[index] = i;
		
		sequence( index+1, i+1, n, m);	// 다음 index에 접근 
		
		decide[i] = false;
			
	}
}
#endif

#ifdef SELECT

// select(1, 0, n, m);
void select(int index, int selected, int n, int m)
{
	if( selected == m )
	{
		for( int i=0; i<m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	if(index > n)
		return;					// 더이상 선택할 것이 없으므로 종료 
			
	ans[selected] = index;					// 인덱스를 결과에 추기하는 부분 
	select(index+1, selected+1, n, m);		//
	
	ans[selected] = 0;						// 인덱스를 결과에 추가하지 않는 부분 
	select(index+1, selected, n, m);		//	
}
#endif

int main()
{
	int n,m;
	cin >> n >> m;
	
#ifdef SEQUENCE	
	sequence(0, 1, n, m);
#endif

#ifdef SELECT
	select(1, 0, n, m);
#endif
		
	return 0;
}

