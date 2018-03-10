#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, num, odds=0, evens=0, ans=0;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> num;
            if (num % 2 != 0)
                odds++;
            else 
                evens++;
        }
        if (evens > 0 || odds > 1)
            ans = 1;
        if (odds%2 != 0)
            ans++;

        cout << ans << endl;
    }
    
    return 0;
}   