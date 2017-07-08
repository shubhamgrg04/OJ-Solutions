#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
 
int main(){
	ios::sync_with_stdio(false);
	int n,l;
	cin >> n >> l;
	int kefa[n], sasha[n];
	for(int i=0; i<n; i++){
		cin >> kefa[i];
	}
	for(int i=0; i<n; i++){
		cin >> sasha[i];
	}

	int kdif[n], sdif[n];
	for(int i=1; i<n; i++){
		kdif[i] = kefa[i] - kefa[i-1];
	}
	kdif[0] = (l-kefa[n-1]) + kefa[0];
	for(int i=1; i<n; i++){
		sdif[i] = sasha[i] - sasha[i-1];
	}
	sdif[0] = (l-sasha[n-1]) + sasha[0];

	for(int i=0; i<n; i++){
		int j=0;
		for(; j<n; j++){
			if(sdif[j] != kdif[(i+j)%n]) break;
		}
		if(j==n) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}