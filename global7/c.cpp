#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long mul(long long a, long long b, long long MOD) {
    return (a * b) % MOD;
}

int main() {
    const int MOD = 998244353;
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int& i: p) cin >> i;
    long long res = 1;
    int l = -1;
    for (int i = 0; i < n; i++) if (p[i] > n - k) {
        if (l != -1) res = mul(res, i - l, MOD);
        l = i;
    }
    cout << mul(k, 2 * n - k + 1, INF) / 2 << " " << res << '\n';
}