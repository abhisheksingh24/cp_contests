#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void testCase() {
    string s;
    cin >> s;
    const int n = s.length();
    if (n % 2) {
        cout << 0 << '\n';
        return;
    }
    vector<int> Z = z_function(s);
    vector<bool> valid(n, false);
    for (int i = 1; i < n; i++) {
        if (Z[i] >= i && 2 * i < n) valid[2 * i] = true;
    }
    // for (int i: Z) cerr << i << " "; cerr << '\n';
    // for (auto i: valid) cerr << i << " "; cerr << '\n';   
    reverse(s.begin(), s.end()); 
    Z = z_function(s);
    vector<bool> valid2(n, false);
    for (int i = 1; i < n; i++) {
        if (Z[i] >= i && n - 2 * i >= 0) valid2[n - 2 * i] = true; 
    }
    // for (auto i: valid) cerr << i << " "; cerr << '\n';   
    // for (int i: Z) cerr << i << " "; cerr << '\n';

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (valid[i] && valid2[i]);
    cout << cnt << endl;
}