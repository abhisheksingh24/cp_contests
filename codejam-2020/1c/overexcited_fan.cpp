#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        testCase();
    }
}

int solve(int x, int y, string &M) {
    if (x == 0 && y == 0) return 0;
    int t = 0;
    for (char c: M) {
        if (c == 'E') x++;
        else if (c == 'W') x--;
        else if (c == 'N') y++;
        else y--;
        t++;
        if (abs(x) + abs(y) <= t) return t;
    }
    return -1;
}

void testCase() {
    int x, y;
    string M;
    cin >> x >> y >> M;
    int res = solve(x, y, M);
    if (res == -1) cout << "IMPOSSIBLE\n";
    else cout << res << '\n';
}