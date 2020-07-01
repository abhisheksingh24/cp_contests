#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testCase();
    }
}

bool solve(int s, int k, int n, vector<int>& res) {
    if (s == n) return true;
    int x = n - s - k;
    if (x >= 0 && x <= k) {
        res.push_back(x);
        return true;
    }
    x = min(k, (n - s) / 2 - k);
    //cerr << s << " " << k << " " << x << '\n' ;
    if (x < 0) return false;
    res.push_back(x);
    return solve(s + k + x, k + x, n, res);
}

void testCase() {
    int n;
    cin >> n;
    vector<int> res;
    if (solve(1, 1, n, res)) {
        cout << res.size() << '\n';
        for (int &i: res) cout << i << " ";
        cout << '\n';
    } else cout << -1 << '\n';
    
}