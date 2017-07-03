#include <iostream>
#include <vector>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

int n, m;

string findmin(string &s, string &t, int i, int j){
	if(i==n) return "";
	if(s[i]==t[j]) {
		return findmin(s,t,i+1,j+1);
	} else {
		//replace.push_back(i);
		string rep = (char)(i+1+'0') + findmin(s,t,i+1,j+1);
		string repnot = findmin(s,t,i,j+1);
		if(rep.length()<repnot.length())
			return rep;
		else
			return repnot;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	string s, t;
	cin >> n >> m >> s >> t;
	cout << findmin(s,t,0,0);
	return 0;
}