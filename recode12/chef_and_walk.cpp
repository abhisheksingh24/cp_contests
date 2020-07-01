#include<bits/stdc++.h>

using namespace std;

inline int add(int a, int b, int m = 1e9 + 7) {
    return ((a % m) + (b % m)) % m;
}

inline int mul(int a, int b, int m = 1e9 + 7) {
    return ((long long) (a % m) * (b % m)) % m;
}

void testCase();

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testCase();
    }
}

int pre(int n) {
    return mul(n, n - 1);
}

int walk(int times, int n) {
    return add(mul(2, mul(times, n)), mul(times - 1, times));
}

void testCase() {
    int n, k;
    cin >> n >> k;
    if (n == 0) {
        cout << mul(k, k + 1) << '\n';
        return;
    }
    int res = pre(n);
    int times = k / 2;
    res = add(res, walk(times, n));
    int rem = k - times * 2 + 1;
    assert(rem <= 2);
    res = add(res, n);
    if (--rem) res = add(res, mul(2, times));
    cout << res << '\n';
}