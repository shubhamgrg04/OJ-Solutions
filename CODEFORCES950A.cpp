#include<iostream>

using namespace std;

int abs(int a) {
    return (a>=0)?a:-a;
}

int main() {
    int l, r,a;
    cin >> l >> r >> a;

    int used = min(a, abs(l-r));
    if(l<r) {
        l = l + used;
    } else {
        r = r + used;
    }
    int ans = min(l,r) + (a-used)/2;
    cout << 2*ans << endl;
}