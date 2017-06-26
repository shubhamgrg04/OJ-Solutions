#include <iostream>
#include <set>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	set<string> set;
	for(int i=0; i<s.length(); i++){
		set.insert(s.substr(i,s.length()-i) + s.substr(0, i));
	}
	cout << set.size();
	return 0;
}