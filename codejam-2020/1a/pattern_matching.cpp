#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        testCase();
    }
}

bool sub(string a, string b) {
    if (a.length() < b.length()) return sub(b, a);
    //cerr << b << " " << a << '\n';
    if (b.length() == 0) return true;
    //cerr << "matching " << a.substr(a.length() - b.length(), b.length()) << " " << b << '\n'; 
    return a.substr(a.length() - b.length(), b.length()) == b;
}

bool sub2(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return sub(a, b);
}

void testCase() {
    int n;
    cin >> n;
    vector<string> p(n);
    for (auto& pi: p) cin >> pi;
    vector<int> firsts(n), lasts(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].length(); j++) {
            if (p[i][j] == '*') lasts[i] = j;
        }
        for (int j = (int) p[i].length() - 1; j >= 0; j--) {
            if (p[i][j] == '*') firsts[i] = j;
        }
    }
    string subFirst, subLast;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        string cur = p[i].substr(0, firsts[i]);
        //cerr << cur << '\n';
        if (!sub2(subFirst, cur)) {
            //cerr << "here, " << subFirst << " " << cur << '\n';
            possible = false;
            break;
        }
        if (cur.length() > subFirst.length()) subFirst = cur;
    }
    for (int i = 0; i < n; i++) {
        if (lasts[i] + 1 == p[i].length()) continue;
        string cur = p[i].substr(lasts[i] + 1, p[i].length() - lasts[i] - 1);
        //cerr << cur << '\n';

        if (!sub(subLast, cur)) {
            possible = false;
            break;
        }
        if (cur.length() > subLast.length()) subLast = cur;
    }

    string rest;
    for (int i = 0; i < n; i++) {
        string cur;
        for (int j = firsts[i] + 1; j < lasts[i]; j++) {
            if (p[i][j] != '*') cur.push_back(p[i][j]);
        }
        rest += cur;
    }

    if (possible) cout << subFirst + rest + subLast << '\n';
    else cout << "*\n";
}