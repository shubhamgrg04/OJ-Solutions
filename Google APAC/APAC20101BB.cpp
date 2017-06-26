#include<iostream>
#include<vector>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	// ios::sync_with_stdio(false);
	int c = in();
	for(int a=1; a<=c; a++){
		int n=in(), k=in(), b=in(), t=in(), ans=0;
		vector<int> pos(n), speed(n), slow(n+1,0);
		for(int i=0; i<n; i++) pos[i] = in();
		for(int i=0; i<n; i++) speed[i] = in();
		int i;
		for(i=n-1; i>=0; i--){
			if((float)(b-pos[i])/(float)speed[i] > (float)t) slow[i] = 1+slow[i+1];
			else {
				slow[i] = slow[i+1];
				ans += slow[i];
				k--;
			}
			if(k==0) { 
				cout << "Case #" << a << ": " << ans << "\n";
				break;
			}
		}
		if(i<0) cout << "Case #" << a << ": " << "IMPOSSIBLE" << "\n";
		
	}
	return 0;
}