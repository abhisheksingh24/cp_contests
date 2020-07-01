#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i: a) cin >> i;
        int mx = -INF;
        int tym = 0;
        for (int i: a) {
            if (i < mx) {
                tym = max(tym, (int) ceil(log2(mx - i + 1)));
            }
            else mx = i;
        }
        cout << tym << '\n';
    }
}