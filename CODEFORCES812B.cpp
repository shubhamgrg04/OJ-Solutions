#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
#define LEFT 0
#define RIGHT 1
int input[15][102];
int dp[15][2];
int n,m;

int countsteps(int dir, int floor){
	int steps = 0;
	if(dir == LEFT){
		for(int i=1; i<m+1; i++){
			if(input[floor][i]==1) steps = i;
		}
	}

	if(dir == RIGHT){
		for(int i=m; i>0; i--){
			if(input[floor][i]==1) steps = m+1-i;
		}
	}
	return steps;
}
 
int main(){
	ios::sync_with_stdio(false);
	n = in() , m = in();

	string s(m+2,'0');
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<m+2; j++){
			input[i][j] = s[j] - '0';
		}
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++)
			dp[i][j] = 0;

	dp[0][LEFT] = countsteps(LEFT,0);
	dp[0][RIGHT] = countsteps(RIGHT,0);
	for(int i=1; i<n; i++){
		int leftsteps = countsteps(LEFT,i), rightsteps = countsteps(RIGHT,i);
		dp[i][LEFT] = min(leftsteps+((dp[i-1][LEFT]>0)?(dp[i-1][LEFT]+leftsteps+1):0) , ((dp[i-1][RIGHT]>0)?(m+1+1+dp[i-1][RIGHT]):leftsteps));
		dp[i][RIGHT] = min(rightsteps+((dp[i-1][RIGHT]>0)?(rightsteps+1+dp[i-1][RIGHT]):0) , ((dp[i-1][LEFT]>0)?(m+1+1+dp[i-1][LEFT]):rightsteps));
		// cout << "i:" << i << " leftsteps:" << leftsteps << " rightsteps:" << rightsteps << " dp[LEFT]:" << dp[i][LEFT] << " dp[RIGHT]:" << dp[i][RIGHT] << endl;
	}
	cout << dp[n-1][LEFT];
	return 0;
}