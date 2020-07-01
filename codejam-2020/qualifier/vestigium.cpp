#include<bits/stdc++.h>

using namespace std;

int trace(auto& mat) {
    int res = 0;
    for (int i = 0; i < mat.size(); i++) res += mat[i][i];
    return res;
}

int rows(auto& mat) {
    int res = 0;
    for (auto& row: mat) {
        set<int> found;
        bool repeats = false;
        for (auto& cell: row) {
            if (found.count(cell)) {
                repeats = true;
                break;
            }
            found.insert(cell);
        }
        if (repeats) res++;
    }
    return res;
}

int cols(auto mat) {
    const int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) swap(mat[i][j], mat[j][i]);
    }
    return rows(mat); 
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<vector<int> > mat(n, vector<int>(n));
        for (auto &row: mat) for (auto &cell: row) cin >> cell;
        cout << "Case #" << tt << ": " << trace(mat) << " " << rows(mat) << " " << cols(mat) << '\n';
    }
}