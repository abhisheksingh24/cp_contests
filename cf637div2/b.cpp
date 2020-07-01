#include<bits/stdc++.h>

using namespace std;

bool isPeak(int i, vector<int>& a) {
    if (i == 0 || i + 1 == a.size()) return false;
    return a[i] > a[i - 1] && a[i] > a[i + 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& i: a) cin >> i;
        int l = 0, peaks = 0, r = 1, ans = 0, best = 0;
        while (r < n) {
            while (r < n && r - l < k) {
                peaks += (isPeak(r++ - 1, a));
            }
            //cerr << l << " " << r << ": " << peaks << '\n';
            if (peaks > ans) {
                ans = peaks;
                best = l;
            }
            peaks -= isPeak(l++ + 1, a);
        }
        cout << ans + 1 << " " << best + 1 << '\n';
    }
}