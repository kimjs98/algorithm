#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	// c, cpp stream sync false 
	cin.tie(NULL);					
	
	int n;
	cin >> n;
	cin.ignore();
	
	while(n--){
			
		string str;
		getline( cin , str );	// 입력 
		str += '\n';  			// 마지막 문자열 구분하기 위해 개행 추가 	
	
		stack<char> s;
	
		for(char ch : str)  //  배열의 각 요소에 대해 코드 실행 
		{
			if(ch == ' ' || ch == '\n'){	
				while(!s.empty()){
					cout << s.top();	
					s.pop();				
				}
				cout << ch;
			}
			else{
				s.push(ch);
			}
		}		
	}
	return 0;
}

