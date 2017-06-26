#include<iostream>
#include<math.h>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	__int64 a , b;
	cin >> a >> b;
	int amoves = 10e4 * sqrt(a/10e8);
	int bmoves = (int)(10e4*sqrt((1+4*b)/10e8)-1.0)/2.0;
	//int bmoves = (sqrt(1+4*b)-1.0)/2.0;
	cout << amoves << "   " << bmoves << endl;
	if(amoves <= bmoves) cout << "Vladik";
	else cout << "Valera";
	return 0;
}