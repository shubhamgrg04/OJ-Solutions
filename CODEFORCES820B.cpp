#include<iostream>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}

float ab(float f){
	if(f<0.0) return -f;
	else return f;
}
 
int main(){
	ios::sync_with_stdio(false);
	int n, a;
	cin >> n >> a;
	float mindiff = 180.0;
	int minvertex;
	for(int i=3; i<=n; i++) {
		float diff = ab(180.0*(((float)i-2.0)/(float)n) - (float)a);
		//cout << diff << " " << mindiff << endl;
		if(diff < mindiff) {
			mindiff = diff;
			minvertex = i;
		}
	}
	cout << "2 1 "<< minvertex;
	return 0;
}