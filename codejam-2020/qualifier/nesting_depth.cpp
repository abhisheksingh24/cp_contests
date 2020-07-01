#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        string s, ss;
        cin >> s;
        int depth = 0;
        for (char c: s) {
            int digit = c - '0';
            while (depth < digit) {
                depth++;
                ss.push_back('(');
            } 
            while (depth > digit) {
                depth--;
                ss.push_back(')');
            }
            ss.push_back(c);
        }
        while (depth--) ss.push_back(')');
        cout << "Case #" << tt << ": " << ss << '\n';
    }
}