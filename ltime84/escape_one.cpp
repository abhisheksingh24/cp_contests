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

long long solve(auto &one) {
    long long INF = 1e13;
    const int n = one.size();
    if (n == 1) return -1;
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = one[i] - one[i - 1] + dp[i - 1];
        if (i - 2 >= 0) dp[i + 1] = min(dp[i + 1], one[i] - one[i - 2] + dp[i - 2]);
    }
    return dp[n];
}

void testCase() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A) cin >> i;
    vector<int> one;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) one.push_back(i);
    }
    cout << solve(one) << '\n';
}