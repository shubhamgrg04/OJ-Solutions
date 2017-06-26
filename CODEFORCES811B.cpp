#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
int perm[10000];
 
int main(){
	ios::sync_with_stdio(false);
	int n = in(), m = in();
	for(int i=0 ; i<n ; i++) perm[i] = in();
	for(int i=0 ; i<m ; i++){
		int l= in() ,r=in() ,x=in(), count = 0;
		for(int j=l-1; j<=r-1; j++){
			if(perm[j]<perm[x-1]) count++;
		}
		if((l+count)==x) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}