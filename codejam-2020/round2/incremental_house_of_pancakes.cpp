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

vector<int> remove_extra(int n, int l = 0, int r = 1e9) {
    if (l == r) {
        return {l, (l * (l + 1)) / 2};
    }
    int m = (l + r + 1) / 2;
    if ((m * (m + 1)) / 2 <= n)
        return remove_extra(n, m, r);
    return remove_extra(n, l, m - 1);
}

int findSum(int beg, int cnt) {
    if (beg % 2) {
        return cnt * cnt - (beg / 2) * (beg / 2); 
    }
    else return cnt * (cnt + 1) - (beg / 2 - 1) * (beg / 2);
}

vector<int> removeMax(int n, int beg, int l = 0, int r = 1e9) {
    if (l == r) {
        int cnt = l - (beg - 1) / 2;
        int sm = findSum(beg, l);
        return {cnt, sm};
    }
    int m = (l + r + 1) / 2;
    int sm = findSum(beg, m);
    
    // if (r < 10) cerr << "sum: " << beg << " " << m << " " << sm << '\n';  

    if (sm <= n) return removeMax(n, beg, m, r);
    else return removeMax(n, beg, l, m - 1);
}

vector<int> solve(int l, int r) {
    vector<int> res = {0, l, r};
    if (l > r) {
        vector<int> extra = remove_extra(l - r);
        res[0] += extra[0];
        res[1] -= extra[1]; 
    }
    else {
        vector<int> extra = remove_extra(r - l);
        res[0] += extra[0];
        res[2] -= extra[1];
    }
    int begL, begR;
    if (res[1] >= res[2]) {
        begL = res[0] + 1;
        begR = res[0] + 2;
    }
    else {
        begR = res[0] + 1;
        begL = res[0] + 2;
    }

    // cerr << '\n';
    // for (int i: res) cout << i << " ";
    // cerr << '\n' << begL << " " << begR << '\n';

    vector<int> maxL = removeMax(res[1], begL);
    vector<int> maxR = removeMax(res[2], begR);
    res[0] += maxL[0] + maxR[0];
    res[1] -= maxL[1];
    res[2] -= maxR[1];
    return res;
}

void testCase() {
    int l, r;
    cin >> l >> r;
    vector<int> rem = solve(l, r);
    for (int i: rem) cout << i << " ";
    cout << '\n';
}