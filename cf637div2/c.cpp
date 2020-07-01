#include<bits/stdc++.h>

using namespace std;

bool possible(vector<int>& p, int mn) {
    if (p.empty()) return true;
    const int n = p.size();
    int beg = n - 1;
    while (p[beg] != mn) beg--;
    for (int i = beg; i + 1 < n; i++) {
        if (p[i] + 1 != p[i + 1]) return false;
    }
    mn = p.back() + 1;
    p.resize(beg); 
    return possible(p, mn);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& i: p) cin >> i;
        if (possible(p, 1)) cout << "Yes\n";
        else cout << "No\n"; 
    }
}