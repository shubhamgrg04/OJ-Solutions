#include <iostream>

using namespace std;

const int MAX = 1e6+1;
int dp[10][MAX] = {0};

int product(int num) {
    int product = 1;
    bool allZero = true;
    while (num>0) {
        if (num%10 > 0) {
            allZero = false;
            product *= num%10;
        }
        num /= 10;
    }
    if (allZero) return 0;
    return product;
}

int main () {
    ios_base::sync_with_stdio(false);
    int q, i=1;
    for (; i<10; i++) {
        for(int j=1; j<10; j++) {
            if (i==j) dp[j][i] = dp[j][i-1] + 1;
            else dp[j][i] = dp[j][i-1];
        }
    }
    for (; i<=MAX-1; i++) {
        for(int j=1; j<10; j++) {
            if (product(i)==j) dp[j][i] = dp[j][i-1] + 1;
            else dp[j][i] = dp[j][i-1];
        }
    }

    cin >> q;
    
    while(q--) {
        int l, r, k, ans=0;
        cin >> l >> r >> k;
        
        ans = dp[k][r] - dp[k][l-1];
        cout << ans << endl;
    }
    
}