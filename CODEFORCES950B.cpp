#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int firstm[n], secondm[m];
    for(int i=0; i<n; i++) {
        cin >> firstm[i];
    }
    for(int i=0; i<m; i++) {
        cin >> secondm[i];
    }
    int sumi=firstm[0], sumj=secondm[0], ans=0;
    for(int i=0, j=0; i<n && j<m; ) {
        if(sumi == sumj) {
            ans++;
            i++; j++;
            sumi = firstm[i];
            sumj = secondm[j];
        }
        else if(sumi < sumj) {
            i++;
            sumi += firstm[i];
        } else {
            j++;
            sumj += secondm[j];
        }
    }

    cout << ans;
}