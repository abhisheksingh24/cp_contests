#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
}

int power(int b, int e) {
    if (e == 0) return 1;
    int res = power(b * b, e / 2);
    if (e % 2) return b * res;
    return res;
}

long long solve(int n) {
    if (n == power(2, log2(n))) return -1;
    int done = 0;
    long long res = 0;
    for (int p = power(2, log2(n)); p >= 1; p /= 2) {
        int cur = n / p - done;
        res += (long long) cur * p;
        done += cur;
    }
    return res - 1;
}

void testCase() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}