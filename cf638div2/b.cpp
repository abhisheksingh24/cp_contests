#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testCase();
    }
}

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    set<int> ints(a.begin(), a.end());
    if (ints.size() > k) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n && ints.size() < k; i++) ints.insert(i);
    int x = 0;
    vector<int> res;
    while (x < n) {
        for (int i: ints) {
            if (x < n && a[x] == i) x++;
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for (int &i: res) cout << i << " ";
    cout << '\n';
}