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

int power(int b, int e) {
    if (e == 0) return 1;
    int res = power(b * b, e / 2);
    if (e % 2) res *= b;
    return res;
}

int solve(int n) {
    int s1 = power(2, n), s2 = 0;
    for (int i = 1; i < n / 2; i++) s1 += power(2, i);
    for (int i = n / 2; i < n; i++) s2 += power(2, i);
    return s1 - s2;
}

void testCase() {
    int n;
    cin >> n;
    cout << solve(n) << '\n';;
}