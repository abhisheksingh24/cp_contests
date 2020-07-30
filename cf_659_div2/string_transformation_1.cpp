#include<bits/stdc++.h>

using namespace std;

int solve(string &a, const string &b) {
    const int n = a.size();
    int steps = 0;
    for (char c = 'a'; c <= 't'; c++) {
        char minChar = 'z';
        for (int i = 0; i < n; i++) if (a[i] == c && b[i] != c) {
            // cerr << i << ": " << a[i] << " to " << b[i] << '\n'; 
            if (a[i] > b[i]) return -1;
            minChar = min(minChar, b[i]);
        }
        if (minChar == 'z') continue;
        for (int i = 0; i < n; i++) if (a[i] == c && b[i] >= minChar) a[i] = minChar;
        steps++;
    }
    return steps;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
}