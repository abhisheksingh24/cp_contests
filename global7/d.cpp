#include<bits/stdc++.h>

const int INF = 1e9;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        const int n = s.length();
        vector<int> rr(n, 1), ll(n, 1);
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                //if (i - k <= n - i - k - 1) rr[i - k] = max(rr[i - k], 2 * k + 1);
                //if (n - i - k - 1 <= i - k) ll[i + k] = max(ll[i + k], 2 * k + 1);
                k++;
            }
            d1[i] = k--;
            //if (i - k <= n - i - k - 1) 
            rr[i - k] = max(rr[i - k], 2 * k + 1);
            //if (n - i - k - 1 <= i - k) 
            ll[i + k] = max(ll[i + k], 2 * k + 1);
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                //if (i - k - 1 <= n - i - k - 1) rr[i - k - 1] = max(rr[i - k - 1], 2 * k + 2);
                //if (n - i - k - 1 <= i - k - 1) ll[i + k] = max(ll[i + k], 2 * k + 2);
                k++;
            }
            d2[i] = k--;
            //if (i - k <= n - i - k - 1) 
            rr[i - k - 1] = max(rr[i - k - 1], 2 * k + 2);
            //if (n - i - k - 1 <= i - k) 
            ll[i + k] = max(ll[i + k], 2 * k + 2);
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        for (int& i: rr) cerr << i << " "; cerr << '\n';
        for (int& i: ll) cerr << i << " "; cerr << '\n';
        int ind = 0;
        for (int i = 1; 2 * i <= n; i++) {
            cerr << i << " " << rr[i] << " " << ll[i] << '\n';
            if (s[i - 1] != s[n - i]) break;
            if (ind + max(rr[ind], ll[n - ind - 1]) < i + max(rr[i], ll[n - i - 1])) ind = i;
        }

        cerr << ind << '\n';

        if (rr[ind] >= ll[n - ind - 1]) {
            cout << s.substr(0, ind) << s.substr(ind, rr[ind]);
            if (ind) cout << s.substr(n - ind, ind);
            cout << '\n';
        } else {
            cout << s.substr(0, ind) << s.substr(n - ind - ll[n - ind - 1], ll[n - ind - 1]);
            if (ind) cout << s.substr(n - ind, ind);
            cout << '\n';
        }
    }
}