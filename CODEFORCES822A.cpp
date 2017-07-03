#include <iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

int fact(int a){
	if(a==1) return 1;
	return a*fact(a-1);
}
 
int main(){
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << fact(min(a,b));
	return 0;
}