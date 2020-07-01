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

bool possible(string a, string b) {
    const int n = a.length();
    set<char> A, B;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) return false;
        A.insert(a[i]);
        B.insert(b[i]);
    }
    for (char c: B) {
        if (!A.count(c)) return false;
    }
    return true;
}

auto findIndices(string s) {
    const int n = s.length();
    vector<vector<int> > ind(26);
    for (int i = 0; i < n; i++) {
        ind[s[i] - 'a'].push_back(i);
    }
    return ind;
}

auto solve(string a, string b) {
    auto indA = findIndices(a);
    auto indB = findIndices(b);
    vector<vector<int> > result;
    for (int c = 25; c >= 0; c--) {
        int pivot = -1;
        vector<int> others;
        for (int i: indB[c]) {
            if (a[i] - 'a' != c) others.push_back(i);
        }
        if (others.empty()) continue;
        others.push_back(indA[c][0]);
        result.push_back(others);
    }
    return result;
}

void testCase() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (!possible(a, b)) {
        cout << -1 << '\n';
        return;
    }
    auto moves = solve(a, b);
    cout << moves.size() << '\n';
    for (auto move: moves) {
        cout << move.size();
        for (int i: move) cout << " " << i;
        cout << '\n';
    }    
}