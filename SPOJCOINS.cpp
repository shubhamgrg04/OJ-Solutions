#include <iostream>
#include <map>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
map<int,long long> mem;

long long max(long long a, long long b){
	return (a>b)?a:b;
}

long long countmax(int val){
	if(val<=0) return 0;
	if(mem[val]!=0) return mem[val];
	return mem[val] = max( val, countmax(val/2) + countmax(val/3) + countmax(val/4) );
}
 
int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n){
		cout << countmax(n) << endl;
	}
	return 0;
}