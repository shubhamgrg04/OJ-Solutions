#include <iostream>
#include <math.h>
#include <string.h>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
int input[20][20];
long long dp[1048576];
int n=20;

int level(int a){
	int ans = 0;
	for(int i=0; i<20; i++){
		if(a>>i & 1) ans++;
	}
	return ans;
}

void printstate(int a){
	for(int i=0; i<n; i++){
		cout << (a>>(n-1-i) & 1);
	}
	cout << endl;
}

long long calc(int state){
	int lvl = level(state);
	printstate(state);
	if(lvl==n) { return 1; cout << "Highest level reached" << endl;}
	if(dp[state]!=-1) { cout << "Saved solution returning " << endl; return dp[state]; }
	dp[state] = 0;
	for(int i=0; i<n ; i++){
		int next = (input[lvl][i])<<(n-1-i);
		if(next!=0 && (state & next)==0)
			dp[state] += calc(state | next);
	}
	return dp[state];
}
 
int main(){
	ios::sync_with_stdio(false);
	//printstate(15);
	int t = in();
	while(t--){
		n = in();
		for(int i=0; i<n; i++) 
			for(int j=0; j<n; j++) 
				input[i][j] = in();
		for(int i=0; i<pow(2,n); i++) mem[i] = 0;
		cout << calc(0) << endl;
	}
	return 0;
}