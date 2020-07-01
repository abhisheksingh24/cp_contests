#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t = 1;
    //cin >> t;
    while (t--) testCase();
}

long long gatherMax(long long total, int a, int b) {
    cerr << total << " " << a << " " << b << '\n';
    if (total <= a) return ((long long) a * (a + 1)) / 2 - ((long long) (a - total) * (a - total + 1)) / 2;
    if (b > a) {
        int sec = min(total, (long long) b);
        int fst = total - sec;
        return ((long long) sec * (sec + 1)) / 2 + ((long long) a * (a + 1)) / 2 - ((long long) (a - fst) * (a - fst + 1)) / 2;
    }
    int sec = total - a;
    return ((long long) a * (a + 1)) / 2 + ((long long) sec * (sec + 1)) / 2;
}

void testCase() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> d(n);
    for (int &i: d) cin >> i;
    vector<long long> s, pre, preS;
    pre.push_back(0);
    for (int &i: d) pre.push_back(pre.back() + i);
    for (int &i: d) s.push_back(((long long) i * (i + 1)) / 2);
      preS.push_back(0);
    for (auto &i: s) preS.push_back(preS.back() + i);
    
    for (auto &i: pre) cerr << i << " "; cerr << '\n';
    for (auto &i: preS) cerr << i << " "; cerr << '\n';
  
    long long res = 0;
    for (int beg = 0, ed = 1 % n; beg < n; beg++) {
        cerr << beg << " " << ed << '\n';
        while (pre[ed + 1] - pre[beg] < x) ed = (ed + 1) % n;
        long long full = preS[ed] - preS[beg + 1];
        long long cur = full + gatherMax(x - full, d[beg], d[ed]);
        res = max(res, cur);
        if (ed == (beg + 1) % n) ed = (beg + 2) % n;
    } 
    cout << res << '\n';
}