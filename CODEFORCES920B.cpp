#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int qd=0;
        int got[n];
        for (int i=0,l,r; i<n; i++) {
            cin >> l >> r;
            if (qd>=r) {
                got[i] = 0;
            } else {
                got[i] = qd+1;
                qd++;
            }
        }
        for(int i=0; i<n; i++) {
            cout << got[i] << " ";
        }
        cout << endl;
    }
}