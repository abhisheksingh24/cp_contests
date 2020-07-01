#include<bits/stdc++.h>

using namespace std;

int main() {
    string s, t, res;
    int tt = 0;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[i]) res.push_back(s[i]);
        else {
            if (tt) res.push_back(t[i]);
            else res.push_back(s[i]);
            tt ^= 1;
        }
    }
    if (tt) cout << "impossible\n";
    else cout << res << endl;
}