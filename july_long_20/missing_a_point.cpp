#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, set<int>> Y;
        set<int> all_y; 
        for (int i = 0; i < 4 * n - 1; i++) {
            int x, y;
            cin >> x >> y;
            Y[x].insert(y);
            all_y.insert(y);
        }
        for (auto p: Y) {
            if (p.second != all_y) {
                
            }
        }
    }
}