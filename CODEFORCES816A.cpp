#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

bool checkpalin(int a, int b){
	int arev = (a%10)*10 + (a/10);
	if(arev==b) return true;
	else return false;
}
 
int main(){
	ios::sync_with_stdio(false);
	string in;
	cin >> in;
	//cout << in;
	int hr1 = in[0] - '0', hr2 = in[1] - '0', mm1 = in[3] - '0', mm2 = in[4] - '0';
	int a = hr1*10 + hr2;
	int b = mm1*10 + mm2;
	int ans = 0;
	//cout << a << " " << b << " " << ( (a%10)*10 + (a/10) ) << endl;
	while(1){
		if(checkpalin(a,b)) break;
		if(b<59){
			b++;
		} else {
			b = 0;
			a = (a+1)%24;
		}
		ans++;
	}
	cout << ans;	
	return 0;
}