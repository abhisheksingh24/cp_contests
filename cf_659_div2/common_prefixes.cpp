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
        vector<int> a(n);
        for (int &i: a) cin >> i;
        vector<string> vec(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < vec[i].size() && j < a[i]; j++)
                vec[i + 1].push_back(vec[i][j]);
            for (int j = vec[i].size(); j < a[i]; j++) {
                if (i < 2 || j >= vec[i - 2].size() || vec[i - 2][j] == 'b') {
                    vec[i + 1].push_back('a');
                    vec[i].push_back('a');
                }
                else {
                    vec[i + 1].push_back('b');
                    vec[i].push_back('b');
                }
            }
        }

        char c = 'c';
        for (string &s: vec) {
            s.push_back(c);
            if (c == 'z') c = 'c';
            else c++;
        }
        for (string s: vec) cout << s << '\n';
    }
}