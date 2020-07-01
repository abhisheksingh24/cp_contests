#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i: a) cin >> i;
    vector<long long> pre(n, a[0]);
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    map<long long, int> last;
    last[0] = -1;
    long long res = (1LL * n * (n + 1)) / 2;
    for (int i = 0; i < n; i++) {
        long long s = pre[i];
        cerr << s << " " << res << " " << last.count(s) << '\n';
        if(last.count(s)) res -= last[s] + 2;
        last[s] = i;
    }
    cout << res << endl;
}