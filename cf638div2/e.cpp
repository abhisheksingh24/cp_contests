#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        testCase();
    }
}

long long solve(auto a, auto b, int k) {
    const int n = a.size();
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (a[i] + b[i]) / k;
        int rem = (a[i] + b[i]) % k;
        b[i] = min(b[i], rem);
        if (rem > b[i]) {
            a[i] = rem - b[i];
        } else a[i] = 0;
    }
    long long red = 0, blue = 0;
    for (int &i: a) red += i;
    for (int &i: b) blue += i;
    res += red / k + blue / k;
    return res;
}

long long solve2(auto a, auto b, int k) {
    const int n = 0;
    long long res = 0,red = 0, blue = 0;
    for (int &i: a) red += i;
    for (int &i: b) blue += i;
    res += red / k + blue / k;
    red %= k;
    blue %= k;
    if (red + blue < k) return res;
    for (int i = 0; i < n; i++) {   
        if (min(a[i], red) + min(b[i], blue) >= k) return res + 1;
    }
    return res;
}

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << max(solve2(a, b, k), max(solve(a, b, k), solve(b, a, k))) << '\n';
}