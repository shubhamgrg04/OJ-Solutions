#include <iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

void calculatemultis(string &n1, string multis[]){
	for(int i=1; i<=9; i++){
		int carry = 0;
		multis[i] = "0";
		for(int j=n1.length()-1; j>=0; j--){
			int res = (n1[j] - '0') * i;
			multis[i] = ((char)(((carry + res)%10) + '0')) + multis[i];
			carry = res/10;
		}
	}
	return;
}

string addstrings(string &s1, string &s2){
	string ans;
	int len = max(s1.length(),s2.length());
	for(int i=len-1, carry=0; i>=0; i--){
		int res = (int)((i>s1.length()-1)?0:(s1[i]-'0')) + (int)((i>s2.length()-1)?0:(s2[i]-'0'));
		ans = (char)((res+carry)%10) + ans; 
		carry = (res+carry)/10;
	}
	return ans;
}

string findproduct(string &n1, string &n2, string multis[]){
	string ans = "0";
	for(int i=n2.length(); i>=0; i--){
		string s = multis[(int)(n2[i]-'0')];
		for(int j=i; j>=0; j--) s = s + '0';
		ans = addstrings(ans,s);
	}
	return ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string multis[10]; multis[0] = "0";
	while(t--){
		string n1, n2;
		cin >> n1 >> n2;
		cout << n1 << endl << n2 << endl;
		calculatemultis(n1,multis);
		for(int i=0; i<10; i++) cout << multis[i] << endl;
		cout << findproduct(n1, n2, multis) << endl;
	}
	return 0;
}