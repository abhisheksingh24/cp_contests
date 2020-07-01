#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int kk = k;
    string s;
    cin >> s;
    int ind = 0, tot = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'L') tot += i - ind++;
    cerr << tot << '\n';
    set<int> pos;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') pos.insert(i);
    }
    vector<vector<int> > moves;
    while (k--) {
        vector<int> moved;
        vector<int> newPos; 
        for(int i: pos) {
            if (tot <= k) break;
            moved.push_back(i);
            s[i] = 'L'; s[i + 1] = 'R';
            tot--;
            if (i - 1 >= 0 && s[i - 1] == 'R') newPos.push_back(i - 1);
            if (i + 2 < n && s[i + 2] == 'L') newPos.push_back(i + 1);
        }
        if (moved.empty()) break;
        moves.push_back(moved);
        for (int i: moved) pos.erase(i);
        for (int i: newPos) pos.insert(i);
    }
    if (pos.empty() && kk == moves.size()) {
        for (auto row: moves) {
            cout << row.size();
            for (int i: row) cout << " " << i + 1;
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}