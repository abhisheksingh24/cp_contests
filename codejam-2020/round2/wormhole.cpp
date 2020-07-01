#include<bits/stdc++.h>

using namespace std;

void testCase();

const int INF = 1e9;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        testCase();
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Slope{
    int num, den;

    Slope(int num, int den) {
        if (den == 0) {
            this -> num = 1;
            this -> den = 0;
        }
        else {
            int g = gcd(abs(num), abs(den));
            if (den < 0) g *= -1;
            this -> num = num / g;
            this -> den = den / g;
        }
    }

    bool operator==(const Slope other) const {
        return (this -> num == other.num) && (this -> den == other.den);
    }

    bool operator<(const Slope other) const {
        return (long long) (this -> num) * other.den < (long long) other.num * (this -> den);
    }
};

Slope findSlope(int a, int b, int c, int d) {
    return Slope(b - d, a - c);
}

int cntt(auto &mapp, int n) {
    int res(0), odd(0);
    for (auto p: mapp) {
        res += (p.second.size() / 2) * 2;
        if (p.second.size() % 2) odd++;
    }
    return min(n, res + odd / 2 + 2);
}

void testCase() {
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];

    int res = 1;

    map<Slope, map<int, set<int>>> mapping;
    map<Slope, vector<bool>> done;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            done[findSlope(X[i], Y[i], X[j], Y[j])].assign(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Slope slope = findSlope(X[i], Y[i], X[j], Y[j]);
            if (done[slope][i] && done[slope][j]) continue;
            mapping[slope][i].insert(i);
            mapping[slope][i].insert(j);
            done[slope][i] = true;
            done[slope][j] = true;
        }
    }
    for (auto p: mapping)
        res = max(res, cntt(p.second, n));

    cout << res << '\n';
}