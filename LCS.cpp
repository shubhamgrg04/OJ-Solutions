#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
string dp[100];
string lcs;
string s1, s2;
int lcs_len;
int scs_len;
string scs(200,'x');


void findscs(){
	//	finding longest common subsequence
	for(int i=0 ; i<s1.length() ; i++){
		for(int j=0 ; j<s2.length() ; j++ ){
			if (j-1>=0 && dp[j-1].length()>dp[j].length())
				dp[j] = dp[j-1];
			if(s1[i]==s2[j]){
				if(j-1>=0 && i-1>=0 && dp[j-1].length()+1>dp[j].length()) 
					dp[j] = dp[j-1] + s1[i];
				else dp[j] = s1[i];
			}
			//cout << "i:" << i << " j:" << j << " s1:" << s1[i] << " s2:" << s2[j] << " dp[]:" << dp[j] << endl; 
		}
	}

	lcs = dp[s2.length()-1];
	scs_len = s1.length()+s2.length()-lcs.length();

	int c1=0, c2=0, c3=0, c4=0;
	for(; c4<scs_len ; c4++){
		if(c1<s1.length() && s1[c1]!=lcs[c3]){
			scs[c4] = s1[c1];
			c1++; 
			continue;
		}
		if(c2<s2.length() && s2[c2]!=lcs[c3]){
			scs[c4] = s2[c2];
			c2++; 
			continue;
		}
		if(c3<lcs.length()){
			scs[c4] = lcs[c3];
			c3++;
			c1++;
			c2++;
			continue;
		}
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(false);
	//string m; m = m + 'b'; cout <<m << endl;
	string a;
	getline(cin, a);
	while(!a.empty()){
		int i;
		for(i=0 ; i<a.length() ; i++) if(a[i] == ' ') break;

		//  making s2 the smaller string
		int len1 = i, len2 = a.length()-i;
		if(len1>=len2){
			s1 = a.substr(0,i);
			s2 = a.substr(i+1,a.length()-i);
		} else {
			s2 = a.substr(0,i);
			s1 = a.substr(i+1,a.length()-i);
		}

		for(int j=0; j<s2.length(); j++) dp[j].clear();

		findscs();
		cout << lcs << endl;
		cout << scs.substr(0,scs_len) << endl;
		getline(cin, a);
	}
	return 0;
}