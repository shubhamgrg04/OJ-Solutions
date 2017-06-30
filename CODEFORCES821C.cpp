#include <iostream>
#include <stack>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n = in(), reorders = 0, i = 2*n, prev = 0;
	stack<int> stk;
	string op;
	while(i--){
		cin >> op;
		if(op[0]=='a') {
			int x = in();
			stk.push(x);
		}
		else {
			if(!stk.empty() && stk.top()!=prev+1){
				reorders++;
				while(!stk.empty()){
					stk.pop();
				}
			}
			else if(!stk.empty()) { stk.pop();}
			prev++;
		}
	}
	cout << reorders;
	return 0;
}