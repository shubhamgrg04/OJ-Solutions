#include <iostream>
#include <vector>
 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string s, t;
	int n, m, ans = 0x7fffffff;
	cin >> n >> m >> s >> t;
	vector<int> minreps, tempreps;
	for(int i=0; i<=(m-n); i++){
		int replacement = 0;
		tempreps.clear();
		for(int j=0; j<n; j++){
			if(t[i+j]!=s[j]) {
				replacement++;
				tempreps.push_back(j+1);
			}
		}
		if(replacement<ans){
			ans = replacement;
			minreps = tempreps;
		}
	}
	cout << ans << endl;
	for(int i=0; i<minreps.size(); i++) cout << minreps[i] << " ";
	return 0;
}