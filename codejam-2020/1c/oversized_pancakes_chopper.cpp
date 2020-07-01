#include<bits/stdc++.h>

using namespace std;

#define int long long

void testCase();

int32_t main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        testCase();
    }
}

int solve(long double deg, auto A, int d) {
    int cuts = 0;
    int pieces = 0;
    for (auto &i: A) {
        if (pieces >= d) break;
        if (deg * (d - pieces) < i) break;
        if (i < deg) continue;
        if (i == deg) {
            pieces++;
            i = 0;
            //cerr << deg << " " << i << '\n';
            continue;
        }
        long long p = i / deg;
        if (p * deg != i) continue;
        pieces += p;
        cuts += p - 1;
        i = 0;
    }
    for (auto i: A) {
        if (pieces >= d) break;
        long long p = i / deg;
        p = min(p, d - pieces);
        pieces += p;
        cuts += p;
    }
    if (pieces < d) return -1;
    return cuts;
}

void testCase() {
    int n, d;
    cin >> n >> d;
    vector<long long> A(n);
    for (auto &i: A) cin >> i;
    sort(A.begin(), A.end());
    int mn = d - 1;
    for (long double deg: A) {
        for (int div = 1; div < d; div++) {
            int cur = solve(deg / div, A, d);
            if ( cur != -1) mn = min(mn, cur);
        }
    }
    cout << mn << '\n';
}