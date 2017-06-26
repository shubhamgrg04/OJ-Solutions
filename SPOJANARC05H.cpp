#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
int mem[25][25];
string s;
int n;

bool grea(string s1, string s2){
	int sum1=0, sum2=0;
	for(int i=0; i<s1.length(); i++) sum1 += s1[i]-48;
	for(int j=0; j<s2.length(); j++) sum2 += s2[j]-48;
	return (sum1>=sum2);
}

int subs(int level, string max){
	if(level >= n) return 1;
	int ans = 0;
	for(int i = level ; i < n; i++){
		// cout << "level: " << level << " string: " << s.substr(level,i+1-level) << endl;
		if(grea(s.substr(level,i+1-level), max)!=0) {
			if(mem[level][i]==0) 
				mem[level][i] = subs(i+1, s.substr(level,i+1-level));
			ans += mem[level][i];
		}
		
	}
	return ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int count = 1;
	while(s[0]!='b'){
		n = s.length();
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) mem[i][j] = 0;
		cout << count << ". " << subs(0, (string)"0") << endl;
		cin >> s;
		count++;
	}
	return 0;
}