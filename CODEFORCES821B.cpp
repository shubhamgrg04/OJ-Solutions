#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	long long m = in(), b = in(), ans = 0;

	//	ternary search
	long long low = 0, high = b, mid1, mid2, ban1, ban2;
	while(low<=high){
		mid1 = (low + (high-low)/3);
		mid2 = (high - (high-low)/3);
		ban1 = ((m*b - m*mid1 + 1)*(mid1 + 1)*(m*b - (m-1)*mid1))/2;
		ban2 = ((m*b - m*mid2 + 1)*(mid2 + 1)*(m*b - (m-1)*mid2))/2;
		if(ban1<=ban2) low = mid1+1;
		else high = mid2-1;
		//cout << "ban1 " << ban1 << " ban2 " << ban2 << endl;
	}
	cout << ban2;
	return 0;
}