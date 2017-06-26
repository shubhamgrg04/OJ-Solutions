#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

 
int main(){
	ios::sync_with_stdio(false);
	int n = in(), m = in(), k =in();
	int govs[k];
	vector<int> graph[n+1];
	for( int i=0 ; i<k ; i++ ) {
		govs[i] = in();
	}
	for( int i=0 ; i<m ; i++ ){
		int a = in(), b = in();
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0, maxset = 0, vis[n+1];
	memset(vis,0,sizeof(vis));
	
	for(int i=0 ; i<k ; i++){
		int gov = govs[i];
		int setsize = 1;
		queue<int> q;
		q.push(gov);
		vis[gov] = 1;
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int j=0 ; j<graph[v].size() ; j++){
				int a = graph[v][j];
				if(vis[a]==1) continue;
				vis[a] = 1; 
				setsize++;
				q.push(a);
			}
		}
		if(setsize > maxset) maxset = setsize;
		ans += setsize*(setsize-1)/2;
	}
	int unvis = 0;
	for(int i=1; i<n+1; i++) if(vis[i]==0) unvis++;
	// cout << "ans:" << ans << " maxset:" << maxset << " unvis:" << unvis << endl;
	cout << (ans-m + (maxset+unvis)*(maxset+unvis-1)/2 - maxset*(maxset-1)/2 );
	return 0;
}