#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;

int const INF = 0x7fffffff;

struct voucher {
	int l;
	int r;
	int c;
};

typedef struct voucher vc;
 
inline int in(){int x; cin >> x; return x;}

int smallerl(vc a, vc b){
	return (a.l<b.l);
}

int smallerr(vc a, vc b){
	return (a.r<b.r);
}
 
int main(){
	ios::sync_with_stdio(false);
	int n, x, ans = INF;
	cin >> n >> x;
	vc lsorted[n], rsorted[n], temp;
	for(int i=0,left,right,cost; i<n; i++) {
		cin >> left >> right >> cost;
		temp.l = left;
		temp.r = right;
		temp.c = cost;
		lsorted[i] = temp;
		rsorted[i] = temp;
	}
	sort(lsorted, lsorted+n, smallerl);
	sort(rsorted, rsorted+n, smallerr);
	map<int, int> mincost;

	for(int i=0,j=0; i<n; i++){
		int remtime = x-lsorted[i].r+lsorted[i].l-1;
		for(; rsorted[j].r<lsorted[i].l; j++){
			int dur = rsorted[j].r - rsorted[j].l + 1;
			if(mincost.find(dur)!=mincost.end())
				mincost[dur] = min(mincost[dur], rsorted[j].c);
			else 
				mincost[dur] = rsorted[j].c;
		}
		if(mincost.find(remtime)!=mincost.end()){
			ans = min(ans, lsorted[i].c + mincost[remtime]);
		}
	}

	if(ans!=INF) cout << ans;
	else cout << -1;
	return 0;
}