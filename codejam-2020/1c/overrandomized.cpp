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

int digits(long long num) {
    if (!num) return 0;
    return 1 + digits(num / 10);
}

int firstDig(long long num) {
    if (num < 10) return num;
    return firstDig(num / 10);
}

void testCase() {
    const int MAX = 1e4;
    int u;
    cin >> u;

    bool thirdCase = true;
    set<int> ALL = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    map<char, set<int>> possible;
    for (int i = 0; i < MAX; i++) {
        long long temp;
        string s;
        cin >> temp >> s;
        for (char c: s) {
            if (!possible.count(c)) possible[c] = ALL;
        }
        if (temp != -1 && digits(temp) == s.length()) {
            thirdCase = false;
            for (int d = firstDig(temp) + 1; d <= 9; d++) {
                possible[s[0]].erase(d);
            }
        }
        if (s.size() > 1) possible[s[0]].erase(0);
    }

    if (thirdCase) {
        assert(possible.size() == 10);
        char ch = '0';
        for (auto p: possible) {
            if (p.second.count(0)) {
                cout << p.first;
                ch = p.first;
                break;
            }
        }
        assert(ch != '0');
        for (auto p: possible) {
            if (p.first != ch) {
                assert(p.second.size() >= 9);
                cout << p.first;
            }
        }
        cout << '\n';
        return;
    }

    // for (auto p: possible) {
    //     cerr << p.first << ": ";
    //     for (auto d: p.second) cout << d << " ";
    //     cout << '\n';
    // }

    assert(possible.size() == 10);
    map<int, char> res;
    for (int i = 0; i < 10; i++) {
        int d;
        for (auto p: possible) {
            if (p.second.size() == 1) {
                d = *p.second.begin(); 
                res[d] = p.first;
                break;
            }
        }
        for (auto &p: possible) {
            p.second.erase(d);
        }
    }
    for (int i = 0; i < 10; i++) cout << res[i];
    cout << '\n';
}