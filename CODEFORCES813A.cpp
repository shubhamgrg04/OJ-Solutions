#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n,m,l,r;
	cin >> n;
	int input[n];
	for(int i=0; i<n; i++)
		cin >> input[i];
	cin >> m;
	pair<int,int> intervals[m];
	for(int i=0; i<n; i++){
		cin >> l >> r; 
		intervals[i] = make_pair(l,r);
	}
	return 0;
}