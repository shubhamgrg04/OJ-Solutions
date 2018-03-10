#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string out;
    for (int i=0; i<n; i++) {
        out.push_back(s[i]);
    }
    for (int i=n; i<2*n; i++) {
        out.push_back(s[2*n-(i+1)]);
    }
    cout << out;
}