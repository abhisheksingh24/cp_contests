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

void twoSwaps(auto &swap1, auto &swap2, auto &moves) {
    moves.push_back({swap1[0], swap1[1], swap2[0]});
    moves.push_back({swap1[0], swap2[1], swap2[0]});
}

bool solve(auto &P, auto &moves, int cur = 0, int pr = 0) {
    if (cur >= P.size()) return true;
    if (P[cur] == cur) return solve(P, moves, cur + 1, pr);
    
}

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> P(n);
    for (int &i: P) cin >> i, --i;
    vector<vector<int>> moves;
    if (solve(P, moves)) {
        cout << moves.size() << '\n';
        for (auto &move: moves) {
            cout << move[0] + 1 << " " << move[1] + 1 << " " << move[2] + 1 << '\n';
        }
    }
}