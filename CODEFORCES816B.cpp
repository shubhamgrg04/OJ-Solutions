#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n, k, q;
	cin >> n >> k >> q;
	return 0;
}

#define MN 200000
#define INF 0x7FFFFFFF
map<int,int> mp;
struct data{int l,r,x;}a[MN+5],b[MN+5];
bool cmpl(const data&a,const data&b){return a.l<b.l;}
bool cmpr(const data&a,const data&b){return a.r<b.r;}
int main()
{
	int n,x,i,j,ans=INF;
	n=read();x=read();
	for(i=1;i<=n;++i)
		a[i].l=read(),a[i].r=read(),a[i].x=read(),b[i]=a[i];
	sort(a+1,a+n+1,cmpl);
	sort(b+1,b+n+1,cmpr);
	for(i=j=1;i<=n;++i)
	{
		for(;b[j].r<a[i].l;++j)
			if(!mp[b[j].r-b[j].l+1] || b[j].x<mp[b[j].r-b[j].l+1])
				mp[b[j].r-b[j].l+1] = b[j].x;
		if(mp[x-a[i].r+a[i].l-1])
			ans = min(ans,mp[x-a[i].r+a[i].l-1]+a[i].x);
	}
	printf("%d",ans<INF?ans:-1);
}