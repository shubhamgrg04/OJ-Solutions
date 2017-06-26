#include<iostream>
#include<cstring>
 
using namespace std;
 
inline int in(){int x; cin >> x; return x;}
bool included[10000];
int lowest = 1;

int getnext(){
	while(1){
		if(included[lowest] == false) break;
		lowest++;
	}
	return lowest;
}
 
int main(){
	ios::sync_with_stdio(false);
	int t = in();
	 while(t--){
	 	int n = in(),current=1,count=0;
	 	memset(included,0,sizeof(included));
	 	while(count<n){	
	 		included[current] = true;
	 		cout << current << " ";
	 		current += getnext();
	 		count++;
	 	}
	 	cout << endl;
	 }
	return 0;
}