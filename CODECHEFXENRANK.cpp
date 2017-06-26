#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int t = in();
	while(t--){
		long long u = in(), v = in() , level, rank;
		level = u + v;
		rank = (level+1)*(level+2)/2 - (level-u);
		cout << rank << endl;
	}
	return 0;
}