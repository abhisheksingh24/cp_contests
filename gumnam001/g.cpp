#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    vector<long long> s = {0};
    map<int, int> r;
    for (int &i: a) {
        cin >> i;
        s.push_back(s.back() + i);
    }
    for (int &i: p) {
        cin >> i;
        --i;
    }
    multiset<long long> sums = {s[n]};
    r[0] = n - 1;
    for (int i: p) {
        int l = (--r.upper_bound(i)) -> first;
        int curR = r[l];
        long long curSum = s[curR + 1] - s[l];
        sums.erase(sums.lower_bound(curSum));
        long long newSum1 = s[i] - s[l];
        long long newSum2 = s[curR] - s[i - 1];
        sums.insert(newSum1); 
        sums.insert(newSum2);
        sums.insert(a[i - 1]);
        r[l] = 
    }
}