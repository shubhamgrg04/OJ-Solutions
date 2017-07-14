#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;

struct group{
	float last_increment;
	float height;
};
 
int main(){
	ios::sync_with_stdio(false);
	int n,q;
	cin >> n;
	vector<struct group> groups;
	int cluster[n+1];

	for(int i=0; i<=n; i++){
		cluster[i] = i;
		struct group gp;
		gp.last_increment = numeric_limits<float>::max(), gp.height = 0.0;
		groups.push_back(gp);
	}

	for(int i=1; i<=q; i++){
		int a, b;
		float h;
		cin >> a >> b >> h;
		struct group gp;
		gp.last_increment = min(h-groups[a].height, h-groups[a].height), gp.height = h;
		groups.push_back(gp);

		if( (h-groups[a].height)<groups[a].last_increment && (h-groups[b].height)<groups[b].last_increment ){
			for(int j=1; j<=n; j++){
				if (cluster[j]==a || cluster[j]==b)
					cluster[j] = groups.size()-1;
			}
		}	
	}

	for(int i=1; i<=n; i++) cout << cluster[i] << endl;

	return 0;
}