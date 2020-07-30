#include<bits/stdc++.h>

using namespace std;

#define int long long

// Ignore variable names, too much maths is injurious to health

int hcf(int a, int b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / hcf(a, b);
}

int solve(int m, int d, int w) {
    int D = (d - 1) % w;
    int M = min(m, d);

    if (D == 0) return (M * (M - 1)) / 2; 

    int omega = lcm(D, w);
    int lambda = omega / D;
    int B = (M - 1) / lambda;

    // cerr << D << " " << omega << " " << lambda << " " << M << " " << B << '\n';

    return ((B - 1) * B * lambda) / 2 + (M - B * lambda) * B;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int m, d, w;
        cin >> m >> d >> w;
        cout << solve(m, d, w) << '\n';
    }
}