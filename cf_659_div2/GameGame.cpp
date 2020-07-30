#include<bits/stdc++.h>

using namespace std;

int countPowers(const vector<int> &A, int p) {
    int cnt = 0;
    for (const int &i: A) if ((1 << p) & i) cnt++;
    return cnt;
}

string solve(const vector<int> &A) {
    const int n = A.size();
    for (int p = 31; p >= 0; p--) {
        int cnt = countPowers(A, p);

        if (cnt % 2) {
            if ((cnt - 1) % 4 && n % 2) return "LOSE";
            return "WIN";
        }
    }
    return "DRAW";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int &i: A) cin >> i;
        cout << solve(A) << '\n';
    }
}