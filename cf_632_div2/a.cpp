#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> mat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2) mat[i].push_back('W');
                else mat[i].push_back('B');
            }
        }
        if ((n * m) % 2 == 0) {
            if (mat[n - 1][m - 1] == 'W') mat[n - 1][m - 1] = 'B';
            else mat[n - 1][m - 2] = 'B';
        } 
        for (auto row: mat) cout << row << '\n';
    }
}