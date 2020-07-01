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

string solve(string s, int k) {
    const int n = s.size();
    sort(s.begin() ,s.end());
    if (k == 1) return s;
    if (n == k) return string(1, s[n - 1]);
    if (s[0] == s[n - 1]) {
        int t = (n + k - 1) / k;
        return string(t, s[0]);
    }
    if (s[0] != s[k - 1]) return string(1, s[k - 1]);
    if (s[0] == s[k]) return s.substr(k - 1, n - k + 1);
    if (s[k] == s[n - 1]) {
        int t = (n - 1) / k;
        return string(1, s[0]) + string(t, s[k]);
    }
    return s.substr(k - 1, n - k + 1);
}

void testCase() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(s, k) << '\n';
}