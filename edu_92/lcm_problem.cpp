#include<bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int y = 2 * l;
        if (y > r) cout << -1 << " " << -1 << '\n';
        else cout << l << " " << y << '\n';
    }
}