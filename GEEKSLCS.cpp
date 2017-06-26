#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
int dp[101][101];
string s1, s2;
string scs(201,'x');


void findscs(){
	//	calculating longest common subsequence
	for(int i=0 ; i<s1.length() ; i++){
		for(int j=0 ; j<s2.length() ; j++ ){
			dp[i][j] = max((i-1>=0)?dp[i-1][j]:0 , (j-1>=0)?dp[i][j-1]:0);
			if(s1[i] == s2[j]) dp[i][j] = max(((i-1>=0 && j-1>=0)?dp[i-1][j-1]:0) + 1, dp[i][j]);
		}
	}


	//	forming shortest common supersequence
	int lcs = dp[s1.length()-1][s2.length()-1], next = s2.length();
	int scslen = s1.length()+s2.length()-lcs;
	for(int i=s1.length()-1 ; i>=0 ; i--){
		for(int j=next-1 ; j>=0 ; j--){
			if(lcs == dp[i][j] && s1[i]==s2[j]){
				for(int k=next-1 ; k>j ; k--){
					scs[scslen-1] = s2[k];
					scslen--;
				}
				next = j;
				lcs--;
				break;
			}
		}
		scs[scslen-1] = s1[i]; scslen--;
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(false);
	string a;
	getline(cin, a);
	while(!a.empty()){
		int i,j,k;
		for(j=0 ; j<a.length() ; j++) if(a[j] != ' ') break; 
		for(i=j+1 ; i<a.length() ; i++) if(a[i] == ' ') break; 
		for(k=i+1 ; k<a.length() ; k++) if(a[k] != ' ') break; 
		s1 = "a" + a.substr(j,i-j+1);
		s2 = "a" + a.substr(k,a.length()-k);
		findscs();
		cout << scs.substr(1, s1.length() + s2.length() - dp[s1.length()-1][s2.length()-1]-1) << endl;
		getline(cin, a);
	}
	return 0;
}