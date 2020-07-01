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

void op(int i, int n, auto &A, auto &order, auto &done) {
    int l = (i - 1 + n) % n;
    int r = (i + 1) % n;
    A[i] = A[l] | A[r];
    order.push_back(i + 1);
    done[i] = true;
}

void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &i: A) cin >> i;
    vector<int> order;
    vector<bool> done(n, false);
    for (int i = 0; i < n; i++) {
        if ((A[i] | k) == k) continue;
        op(i, n, A, order, done);
    }
    vector<int> lft(n + 1, 0), rt(n + 1, 0);
    for (int i = 0; i < n; i++) lft[i + 1] = A[i] | lft[i];
    for (int i = n - 1; i >= 0; i--) rt[i] = A[i] | rt[i + 1];
    int beg = 0;
    for (int i = 0; i < n; i++) if ((lft[i] | rt[i + 1]) == k) {
        beg = i;
        break;
    }
    for (int i = beg; i < n; i++) if (!done[i]) {
        op(i, n, A, order, done);
    }
    for (int i = 0; i < beg; i++) if (!done[i]) {
        op(i, n, A, order, done);
    }
    int orr = 0;
    for (int &i: A) orr |= i;
    if (orr == k) {
        for (int &i: order) cout << i << " ";
        cout << '\n';
    } else cout << -1 << '\n';
}