#include<bits/stdc++.h>

using namespace std;

vector<vector<long long> > pascal, rowSum;

void makePascal() {
    pascal.push_back({1});
    for (int i = 1; i < 500; i++) {
        pascal.push_back({1});
        for (int j = 0; j < i - 1; j++) {
            pascal[i].push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
            if (pascal[i][j] >= 1e9) break;
        }
        pascal[i].push_back(1);
    }
    rowSum.resize(pascal.size());
    for (int i = 0; i < pascal.size(); i++) {
        rowSum[i].push_back(1);
        for (int j = 1; j < pascal[i].size(); j++) {
            rowSum[i].push_back(rowSum[i].back() + pascal[i][j]);
        }
    }
}

void testCase();

int main() {
    int t;
    cin >> t;
    makePascal();
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": \n";
        testCase();
    }
}

void testCase() {
    int n;
    cin >> n;
    long long s = 1;
    int x = 0, y = 0;
    vector<pair<int, int> > pos(1, {1, 1});
    while (s < n) {
        if (rowSum[x + 1][y + 1] <= (n - s)) {
            pos.emplace_back(++x + 1, ++y + 1);
        } else if (rowSum[x + 1][y] <= (n - s)) {
            pos.emplace_back(++x + 1, y + 1);
        } else {
           pos.emplace_back(x + 1, --y + 1);
        }
        s += pascal[x][y];
    }
    cerr << pos.size() << '\n';
    for (auto p: pos) cout << p.first << " " << p.second << '\n';
}