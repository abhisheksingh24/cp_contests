#include<bits/stdc++.h>

using namespace std;

#define int long long

void testCase();

string query(int x, int y) {
    cout << x - 1e9 << " " << y - 1e9 << endl;
    cout.flush();
    string response;
    cin >> response;
    return response;
}

int leftmost(int h, int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2;
    string res = query(m, h);
    if (res == "MISS") return leftmost(h, m + 1, r);
    else return leftmost(h, l, m);
}

int rightmost(int h, int l, int r) {
    if (l == r) return l;
    int m = (l + r + 1) / 2;
    string res = query(m, h);
    if (res == "MISS") return rightmost(h, l, m - 1);
    else return rightmost(h, m, r);
}

int lowermost(int x, int d, int u) {
    if (d == u) return d;
    int m = (d + u) / 2;
    string res = query(x, m);
    if (res == "MISS") return lowermost(x, m + 1, u);
    else return lowermost(x, d, m);
}

int uppermost(int x, int d, int u) {
    if (d == u) return d;
    int m = (d + u + 1) / 2;
    string res = query(x, m);
    if (res == "MISS") return uppermost(x, d, m - 1);
    else return uppermost(x, m, u);
}

pair<int, int> getFirstPoint() {
    vector<pair<int, int> > pts = { {1e9, 1e9}, 
                                    {1e9 / 2, 3LL * (1e9 / 2)}, 
                                    {3LL * (1e9 / 2), 3LL * (1e9 / 2)}, 
                                    {3LL * (1e9 / 2), 1e9 / 2}, 
                                    {1e9 / 2, 1e9 / 2} };
    for (auto p: pts) {
        if (query(p.first, p.second) != "MISS") return p;
    }
    return {-1, -1};
}


int32_t main() {
    int t, a, b;
    cin >> t >> a >> b;
    while (t--) {
        pair<int, int> p = getFirstPoint();
        assert(p != make_pair(-1LL, -1LL));
        int l = leftmost(p.second, 0, p.first);
        int r = rightmost(p.second, p.first, 2e9);
        int m = (l + r) / 2;
        int u = uppermost(m, p.second, 2e9);
        int d = lowermost(m, 0, p.second);
        string result = query(m, (u + d) / 2);
        assert(result == "CENTER");
    }
}
