#include <iostream>
#include <map>
#include <set>
#include <limits>
 
using namespace std;


// this code operates on a input like below :
// 44 8
// 0 35 0.000
// 4 23 0.241
// 28 45 0.367
// 36 37 0.370
// 6 46 0.484
// 19 40 0.566
// 11 20 0.591
// 2 15 .363
 
int main(){
	ios::sync_with_stdio(false);
	int n,q;

	// n is the number of original elements
	// q is the number of cluster unions

	cin >> n >> q;

	// elements with same clustnum belongs to same cluster
	// example: 0 and 35 form a new cluster called 45
	// cluters map contains information (last increment & height) about each cluster 

	int clustnum[n+1];
	map< int, pair<float,float> > clusters;

	// initialiazing clustnum array and clusters map

	for(int i=0; i<=n; i++){
		clustnum[i] = i;
		clusters[i] = make_pair(numeric_limits<float>::max(), 0);
	}

	// building the clustnum array while taking input

	for(int i=1; i<=q; i++){
		int a, b;
		float h;
		cin >> a >> b >> h;

		// if there is no cluster corresponding to a or b then it means 
		// those clusters already broke the required condition

		if( clusters.find(a)==clusters.end() || clusters.find(b)==clusters.end())
			continue;

		// checking if the combining clusters have less increment than
		// there last increments. if they satisfy condition, then we form 
		// a new cluster, otherwise we leave it without forming any cluster

		if( (h-clusters[a].second)<clusters[a].first && (h-clusters[b].second)<clusters[b].first ){
			for(int j=0; j<=n; j++){
				if (clustnum[j]==a || clustnum[j]==b)
					clustnum[j] = n+i;
			}
			int last_increment = min(h-clusters[a].second, h-clusters[b].second);
			clusters[n+i] = make_pair(last_increment,h);
		}	
	}

	cout << "Elements with same value are in same cluster" << endl;
	set<int> parent;
	for(int i=0; i<=n; i++) {
		cout << clustnum[i] << endl;
		parent.insert(clustnum[i]);
	}
	// cout << "Total no. of clusters are " << parent.size();

	return 0;
}