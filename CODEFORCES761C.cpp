#include <iostream>
#include <vector>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string input[n];
	for(int i=0; i<n; i++){
		cin >> input[i];
	}
	vector<int> minc(n), mini(n), mins(n);
	for(int i=0; i<n; i++){
		minc[i] = m;
		mini[i] = m;
		mins[i] = m;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(input[i][j]>='a' && input[i][j]<='z'){
				minc[i] = min(minc[i],min(j,m-j));
			}
			else if(input[i][j]>='0' && input[i][j]<='9'){
				mini[i] = min(mini[i],min(j,m-j));
			}
			else if(input[i][j]=='#' || input[i][j]=='*' || input[i][j]=='&' ){
				mins[i] = min(mins[i],min(j,m-j));
			}
		}
	}
	int ans = n*m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n ; j++){
			if(j!=i) {
				for(int k=0; k<n; k++){
					if(k!=j && k!=i){
						ans = min(ans,minc[i]+mini[j]+mins[k]);
					}
				}
			}
		}
	}
	cout << ans;

	return 0;
}