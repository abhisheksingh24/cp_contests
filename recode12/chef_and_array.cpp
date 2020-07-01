#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAX = 1e15;

struct node;
node *newNode();

struct node {
    int lv, rv, sum;
    node *left, *right;
 
 
    node() : left(NULL), right(NULL), sum(0) {}
 
 
    inline void init(int l, int r) {
        lv = l;
        rv = r;
    }
 
 
    inline void extend() {
        if (!left) {
            int m = (lv + rv) / 2;
            left = newNode();
            right = newNode();
            left->init(lv, m);
            right->init(m + 1, rv);
        }
    }
 
 
    int getSum(int l, int r) {
        if (r < lv || rv < l) {
            return 0;
        }
 
        if (l <= lv && rv <= r) {
            return sum;
        }
 
        extend();
        return (left->getSum(l, r) + right->getSum(l, r)) % MOD;
    }
 
 
    void update(int p, int newVal) {
        if (lv == rv) {
            sum = newVal;
            return;
        }
 
        extend();
        (p <= left->rv ? left : right)->update(p, newVal);
        sum = (left->sum + right->sum) % MOD;
    }
};
 
 
node *newNode() {
    static int bufSize = 1e7;
    static node buf[(int) 1e7];
    assert(bufSize);
    return &buf[--bufSize];
}

void testCase();

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        testCase();
    }
}

void testCase() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &i: A) cin >> i;
    long long curS = 0;
    node *I = newNode(), *cnt = newNode();
    I -> init(0, 2 * MAX);
    cnt -> init(0, 2 * MAX);

    I -> update(MAX, 1);
    cnt -> update(MAX, 1);

    int res = 0;
    for (int r = 0; r < n; r++) {
        int R = r + 1;
        int req = curS - k;
        int a = (n - R + 1);
        int b = n - R;
        if (a % 2) b /= 2;
        else a /= 2;
        int ab = (a * b) % MOD;
        res = (res + (((n - R + 1) * (I -> getSum(req + 1 + MAX, 2 * MAX))) % MOD)
                     + (((cnt -> getSum(req + 1 + MAX, 2 * MAX)) * ab) % MOD)) % MOD;

        curS += A[r];
        int val1 = (I -> getSum(curS + MAX, curS + MAX));
        int val2 = (cnt -> getSum(curS + MAX, curS + MAX));
        I -> update(curS + MAX, (val1 + R + 1) % MOD);
        cnt -> update(curS + MAX, (val2 + 1) % MOD);
    }
    cout << res << '\n';
}