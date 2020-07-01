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

string solve(long long x, long long y) {
    string res;
    for (long long i = 0, val = 1; ; i++, val *= 2) {
        if ((x & i) && (y & i)) return "IMPOSSIBLE";
        if (x & i) {
            if (x > 0) res += "E";
            else res += "W";
        }
        else if (y & i) {
            if (y > 0) res += "N";
            else res += "S";
        } 
        else return "IMPOSSIBLE";
    }
    return res;
}

void testCase() {
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
}