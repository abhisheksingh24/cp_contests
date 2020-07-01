#include<bits/stdc++.h>

using namespace std;

vector<vector<vector<int> > > all;

int trace(auto mat) {
    int res = 0;
    for (int i = 0; i < mat.size(); i++) res += mat[i][i];
    return res;
}

bool symmetric(auto& mat) {
    return true;
    const int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i]) return false;
        }
    }
    return true;
}

bool valid(auto& mat, int val, int x, int y) {
    for (int i = 0; i < x; i++) {
        if (mat[i][y] == val) return false; 
    }
    for (int j = 0; j < y; j++) {
        if (mat[x][j] == val) return false; 
    }
    mat[x][y] = val;
    return true;
}

bool solve(auto& mat, int k, int x = 0, int y = 0) {
    //cerr << x << " " << y << '\n';
    const int n = mat.size();
    if (x >= n) {
        if (trace(mat) == k) all.push_back(mat);
        return trace(mat) == k && symmetric(mat);
    }
    if (y >= n) return solve(mat, k, x + 1, 0);
    bool found = false;
    for (int val = 1; val <= n; val++) {
        if (valid(mat, val, x, y) && solve(mat, k, x, y + 1)) {
            //all.push_back(mat);
            found = true;
        }
    }
    return found;
}

set<vector<int> > printAllTraces(auto& listOfMat) {
    set<vector<int> > res;
    for (auto& mat: listOfMat) {
        vector<int> trace;
        for (int i = 0; i < mat.size(); i++) {
            trace.push_back(mat[i][i]);
        }
        //sort(trace.begin(), trace.end());
        res.insert(trace);
    }
    for (auto trace: res) {
        for (int i: trace) cout << i << " ";
        cout << endl;
    }
} 

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > mat(n, vector<int>(n));
        cout << "Case #" << tt << ": ";
        if (!solve(mat, k)) cout << "IMPOSSIBLE\n";
        else {
            cout << "POSSIBLE\n";
            printAllTraces(all);
            /*
            for (auto& matt: all) {
                for (auto &row: matt) {
                    for (auto &cell: row) cout << cell << " ";
                    cout << '\n';
                }
                cout << '\n';
            }
            */
        }
    }
}