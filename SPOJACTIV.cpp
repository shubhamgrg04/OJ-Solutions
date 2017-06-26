#include  <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const MOD = 1e8;

inline int in() { int x; cin >> x; return x;}

typedef pair<int,int> pi;

bool smallerfirst(pi a, pi b) {
	if(a.first < b.first) return true;
	return false;
}

int search(int a, vector<pi> &sort_first){
	int low = 0, high = sort_first.size(), mid;
	while(low<high){
		mid = (low+high)/2;
		if(sort_first[mid].first==a) break;
		if(sort_first[mid].first>a && ((mid>0)?sort_first[mid-1].first<a:1) ) break;
		if(sort_first[mid].first<a) low = mid+1;
		if(sort_first[mid].first>a) high = mid-1;
	}
}

int main(){
	int n;
	while((n = in()) != -1) {
		vector<pi> sort_first(n);
		vector<int> mem(n+1); mem[n] = 0;
		int ans = 0;
		for(int i=0; i<n; i++){
			int start = in(), end = in();
			sort_first[i] = make_pair(start,end);
		}
		sort(sort_first.begin(), sort_first.end(), smallerfirst);

		for(int i=n-1; i>=0; i--){
			mem[i] = (((i<n-1)?mem[i+1]:0) + 1 + mem[search(sort_first[i].second, sort_first)]) % MOD;
		}
		cout << mem[0] << '\n';
	}
	return 0;
}
