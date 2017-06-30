#include <iostream>
#include <map>
#include <string.h>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n = in();
	int input[n][n];
	memset(input,0,sizeof(input));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++){
			input[i][j] = in();
		}
	}
	map<int,bool> mp;
	for(int i=0; i<n; i++) {
		mp.clear();
		for(int j=0; j<n; j++){
			mp.insert(make_pair(input[i][j],true));
		}
		for(int j=0; j<n; j++){
			if(input[i][j]!=1){
				int k=0;
				for(; k<n; k++){
					if(i!=k && mp.find(input[i][j] - input[k][j])!=mp.end()) break;
				}
				if(k==n) {cout << "No"; return 0;}
			}
		}
	}

	cout << "Yes";

	return 0;
}