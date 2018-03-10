#include<iostream>
#include<algorithm>

using namespace std;

int main () {
    int t;
    cin >> t;

    while(t--) {
        int n, k, ans;
        cin >> n >> k;
        ans = 0;
        int taps[k], closest_tap[n];
        for (int i=0; i<k; i++) {
            cin >> taps[i];
        }
        for (int i=0; i<n; i++) {
            closest_tap[i] = n;
            for (int j=0; j<k; j++){
                closest_tap[i] = min(closest_tap[i], abs(taps[j]-(i+1))+1);
            }
            ans = max(closest_tap[i], ans);
        }
        cout << ans << endl;
    }

}