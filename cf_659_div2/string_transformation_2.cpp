#include<bits/stdc++.h>

using namespace std;

int solve(string A, string B) {
    const int n = A.size();
    vector<vector<bool>> mat(20, vector<bool>(20, false));
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) mat[A[i] - 'a'][B[i] - 'a'] = true;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 20; k++)  {
                if (i != j && i != k && j != k && mat[j][k] && mat[j][i] && mat[i][k])
                    mat[j][k] = false;
            }
        }

        cerr << "\ni = " << i << "\n\n";
        for (auto row: mat) {
            for (bool cell: row) 
                cerr << cell << " ";
            cerr << '\n';
        }
    }

    int cnt = 0;
    for (auto row: mat) 
        for (bool cell: row) 
            cnt += cell;
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t-- ) {
        int n;
        cin >> n;
        string A, B;
        cin >> A >> B;
        cout << solve(A, B) << '\n';
    }
}