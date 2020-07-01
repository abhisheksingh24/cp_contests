#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int mn = n * (a - b);
        int mx = n * (a + b);
        if (mn <= c - d) {
            if (mx >= c - d) cout << "Yes\n";
            else cout << "No\n";
        } 
        else if (mn <= c + d) cout << "Yes\n";
        else cout << "No\n";
    }
}