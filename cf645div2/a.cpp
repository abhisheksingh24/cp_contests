#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t;
    cin >> t;
    while (t--) testCase();
}

void testCase() {
    int n, m;
    cin >> n >> m;
    int res = n * (m / 2);
    if (m % 2) res += (n + 1) / 2;
    cout << res << '\n';
}