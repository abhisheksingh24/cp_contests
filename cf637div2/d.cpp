#include<bits/stdc++.h>

using namespace std;

void fill(auto& v) {
    v[0][8] = 1;
    v[1][3] = 3;
    v[1][4] = 2;
    v[1][7] = 1;
    v[1][8] = 5;
    v[1][9] = 4;
    v[2][8] = 2;
    v[3][8] = 2;
    v[3][9] = 1;
    v[4][8] = 8;
    v[4][9] = 9;
    v[5][6] = 1;
    v[5][8] = 2;
    v[5][9] = 1;
    v[6][8] = 1;
    v[7][0] = 3;
    v[7][3] = 2;
    v[7][8] = 4;
    v[7][9] = 3;
    v[9][8] = 1;
    for (int i = 0; i <= 9; i++) v[i][i] = 0;
}

void fillDig(auto& v) {
    v["1110111"] = 0;
    v["0010010"] = 1;
    v["1011101"] = 2;
    v["1011011"] = 3;
    v["0111010"] = 4;
    v["1101011"] = 5;
    v["1101111"] = 6;
    v["1010010"] = 7;
    v["1111111"] = 8;
    v["1111011"] = 9;
}

void fillRev(auto& st, auto& dig) {
    for (auto p: dig) {
        st[p.second] = p.first;
    }
}

int chng(string s, int d, auto& st) {
    string s2 = st[d];
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (s[i] == '1' && s2[i] == '0') return -1;
        if (s[i] == '0' && s2[i] == '1') cnt++;
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > change(10, vector<int>(10, -1));
    vector<vector<bool> > dp(n + 1, vector<bool>(k + 1, false));
    map<string, int> dig;
    map<int, string> st;
    fill(change);
    fillDig(dig);
    fillRev(st, dig);
    vector<string> cur(n);
    for (string& i: cur) cin >> i;
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int d = 0; d <= 9; d++) {
                //int ch = change[cur[i]][d];
                int ch = chng(cur[i], d, st);
                if (ch == -1 || ch > j) continue;
                if (dp[i + 1][j - ch]) {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }
    //for (auto row: dp) {for (auto cell: row) cerr << cell; cerr << '\n';}
    vector<int> best(n);
    bool possible = true;
    for (int i = 0; i < n; i++) {
        possible = false;
        for (int d = 9; d >= 0; d--) {
            //int ch = change[cur[i]][d];
            int ch = chng(cur[i], d, st);
            if (ch == -1) continue;
            if (ch > k) continue;
            if (dp[i + 1][k - ch]) {
                best[i] = d;
                k -= ch;
                possible = true;
                break;
            }
        }
        if (!possible) break;
    }
    if (possible) {
        for (int d: best) cout << d;
        cout << '\n';
    }
    else cout << -1 << '\n';    
}