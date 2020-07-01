#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x += b - a;
        y += d - c;
        if (x == x1 && x == x2 && a) cout << "NO\n";
        else if (y == y1 && y == y2 && c) cout << "NO\n";
        else if (x >= x1 && x <= x2 && y >= y1 && y <= y2) cout << "YES\n";
        else cout << "NO\n";
    }
}