#include <iostream>
#include <cstring>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

void bitadd(int l, int v, int bit[]){
	while(l<=200001){
		bit[l] += v;
		l += l&(-l);
	}
}

void bitupdate(int l, int r, int v, int bit[]){
	bitadd(l,v,bit);
	bitadd(r+1,-v,bit);
}

long long bitsum(int l, int bit[]){
	long long sum = 0;
	while(l>0){
		sum += bit[l];
		l -= l&(-l);
	}
	return sum;
}

long long bitrangesum(int l, int r, int bit[]){
	return (bitsum(r, bit)-bitsum(l-1, bit));
}
 
int main(){
	ios::sync_with_stdio(false);
	int n, k, q;
	cin >> n >> k >> q;
	int bit[200001];
	memset(bit,0,sizeof(bit));
	for(int i=0; i<n; i++){
		int l,r;
		cin >> l >> r;
		bitupdate(l,r,1,bit);
	}
	int admi[200001];
	memset(admi,0,sizeof(admi));
	for(int i=0; i<200001; i++){
		if(bitsum(i,bit)>=k)
			bitadd(i,1,admi);
	}
	for(int i=0; i<q; i++){
		int a,b;
		cin >> a >> b;
		cout << bitrangesum(a,b,admi) << "\n";
	}
	return 0;
}