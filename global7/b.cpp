#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& i: b) cin >> i;
    vector<int> a(n);
    a[0] = b[0];
    int mx = max(0, a[0]);
    for (int i = 1; i < n; i++) {
        a[i] = b[i] + mx;
        mx = max(mx, a[i]);
    }
    for (int& i: a) cout << i << " ";
    cout << '\n';
}