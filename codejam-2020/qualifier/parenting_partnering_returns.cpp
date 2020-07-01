#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<array<int, 3> > acts(n);
        for (int i = 0; i < n; i++) {
            cin >> acts[i][0] >> acts[i][1];
            acts[i][2] = i;
        }
        sort(acts.begin(), acts.end());
        string assigned(n, 'x');
        int c = -1, j = -1;
        bool possible = true;
        for (auto& act: acts) {
            if (act[0] >= c) {
                assigned[act[2]] = 'C';
                c = act[1];
            } else if (act[0] >= j) {
                assigned[act[2]] = 'J';
                j = act[1];
            } else {
                possible = false;
                break;
            }
        }
        if (!possible) assigned = "IMPOSSIBLE";
        cout << "Case #" << tt << ": " << assigned << '\n';
    }
}