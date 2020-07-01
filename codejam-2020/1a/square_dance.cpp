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

bool round(auto& mat) {
    const int n = mat.size(), m = mat[0].size();
    vector<pair<int, int> > rem;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) continue;
            bool l = true, r = true, u = true, d = true; 
            int cur = 0, neigh = 0;
            for (int k = 1; k < max(n, m); k++) {
                if (l && j - k >= 0 && mat[i][j - k] != -1) {
                    l = false;
                    cur += mat[i][j];
                    neigh += mat[i][j - k];
                }
                if (r && j + k < m && mat[i][j + k] != -1) {
                    r = false;
                    cur += mat[i][j];
                    neigh += mat[i][j + k];
                }
                if (u && i - k >= 0 && mat[i - k][j] != -1) {
                    u = false;
                    cur += mat[i][j];
                    neigh += mat[i - k][j];
                }
                if (d && i + k < n && mat[i + k][j] != -1) {
                    d = false;
                    cur += mat[i][j];
                    neigh += mat[i + k][j];
                }
            }
            if (neigh > cur) rem.emplace_back(i, j);
        }
    }
    for (auto p: rem) {
        //cerr << "Removing " << p.first << " " << p.second << '\n';
        mat[p.first][p.second] = -1;
    }
    // for (auto row: mat) {
    //     for (auto cell: row) cerr << cell << " ";
    //     cerr << '\n';
    // }
    return !rem.empty();
}

long long score(auto& mat) {
    long long res = 0;
    for (auto& row: mat) for (auto& cell: row) if (cell != -1) res += cell;
    return res;
}

void testCase() {
    int r, c;
    cin >> r >> c;
    vector<vector<int> > s(r, vector<int>(c));
    for (auto& row: s) for (auto& cell: row) cin >> cell;
    long long tot = score(s);
    while (round(s)) tot += score(s);
    cout << tot << '\n';
}