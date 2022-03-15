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
		getline( cin , str );	// �Է� 
		str += '\n';  			// ������ ���ڿ� �����ϱ� ���� ���� �߰� 	
	
		stack<char> s;
	
		for(char ch : str)  //  �迭�� �� ��ҿ� ���� �ڵ� ���� 
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

