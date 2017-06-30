#include  <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

int const MOD = 1e8;

inline int in() { int x; cin >> x; return x;}

typedef pair<int,int> pi;

int search(int i, vector<pi> &sort_first){
	int low = i, high = sort_first.size(), mid;
	while(low<=high){
		mid = (low+high)/2;
		//if(sort_first[mid].first==a) break;
		if(sort_first[mid].first>=sort_first[i].second && ((mid>low)?(sort_first[mid-1].first<sort_first[i].second):(1)) ) break;
		if(sort_first[mid].first<sort_first[i].second) low = mid+1;
		if(sort_first[mid].first>=sort_first[i].second) high = mid-1;
	}
	return mid;
}

void displayin8(int a){
	stringstream convert;
	convert << a;
	string num = convert.str();
	while(num.length()<8) num = '0' + num;
	cout << num << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n!=-1) {
		vector<pi> sort_first(n);
		vector<int> mem(n+1); mem[n] = 0; mem[n-1] = 1;
		int ans = 0;
		for(int i=0; i<n; i++){
			int start, end;
			cin >> start >> end;
			sort_first[i] = (pi) {start,end};
		}
		sort(sort_first.begin(), sort_first.end());
		for(int i=n-2; i>=0; i--){
			mem[i] = (mem[i+1] + 1 + mem[search(i, sort_first)]) % MOD;
		}
		displayin8(mem[0]);
		cin >> n;
	}
	return 0;
}
