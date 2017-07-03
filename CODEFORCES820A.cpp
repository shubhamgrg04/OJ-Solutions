#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int i = 1, lastp = v0;
	while(1){
		if(lastp>=c) break;
		i++;
		lastp = lastp + min(v0+(i-1)*a,v1) - l;
	}
	cout << i;
	return 0;
}