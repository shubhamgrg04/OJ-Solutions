#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

int abs(int a){
	if(a<0) return (-a);
	else return a;
}
 
int main(){
	ios::sync_with_stdio(false);
	int even, odd;
	cin >> even >> odd;
	if(even==0 && odd==0){
		cout << "NO";
		return 0;
	}
	if(abs(even-odd)<=1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}