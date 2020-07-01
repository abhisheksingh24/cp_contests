#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<vector<int> > cnt((k + 1) / 2, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            int ind = i % k;
            if (ind >= cnt.size()) ind = k - 1 - ind;
            cnt[ind][s[i] - 'a']++;
        }
        int res = n;
        for (auto vec: cnt) {
            res -= *max_element(vec.begin(), vec.end());
        }
        cout << res << '\n';
    }
}