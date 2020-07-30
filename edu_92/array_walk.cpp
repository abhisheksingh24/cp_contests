#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int> &a, int k, int z) {
    const int n = a.size();
    vector<long long> mxp(n, 0);
    for (int i = 1; i < n; i++) {
        mxp[i] = max(mxp[i - 1], (long long) a[i - 1] + a[i]);
    }

    // for (int i: mxp) cerr << i << " "; cerr << '\n';

    vector<long long> summ(n, 0);
    for (int i = 1; i < n; i++) {
        summ[i] = summ[i - 1] + a[i];
    }

    // for (int i: summ) cerr << i << " "; cerr << '\n';


    long long res = 0; 
    for (int zz = 0; zz <= z; zz++) {
        int r = k - 2 * zz;
        if (r < 0 || (zz > 0 && r < 1)) continue;
        long long cur = summ[r] + mxp[r] * zz;
        // cerr << r << " " << cur << '\n';
        res = max(res, cur);
    }

    return res + a[0];
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        cout << solve(a, k, z) << '\n';
    }
}