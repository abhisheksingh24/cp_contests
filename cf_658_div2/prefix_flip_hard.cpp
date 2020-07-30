#include<bits/stdc++.h>

using namespace std;

void flip(char &c) {
    if (c == '0') c = '1';
    else c = '0';
}

char flipped(char c) {
    // cerr << "Flipping " << c << '\n';
    if (c == '0') {
        // cerr << "returning 1\n";
        return '1';
    }
    // cerr << "returning 0\n";
    return '0';
}

char curChar(string s, int ind, int beg, bool rev) {
    // cerr << "Finding char " << s << " " << ind << " beg = " << beg << " rev = " << rev << '\n';
    if (rev) {
        char c = flipped(s[beg - ind]);
        // cerr << "returning " << c << '\n';
        return c;
    }
    return s[beg + ind];
}

vector<int> solve(string a, string b) {
    const int n = a.size();
    vector<int> res;
    bool rev = false;
    int beg = 0;
    for (int i = n - 1; i >= 1; i--) {
        char c = curChar(a, i, beg, rev);

        // cerr << "curChar = " << c << '\n';

        if (c == b[i]) continue;
        char firstChar = a[0];
        if (rev) flip(firstChar);

        // cerr << "Mismatch\n";
        // cerr << "firstChar = " << firstChar << '\n';

        // cerr << "required = " << b[i] << '\n';
        if (firstChar == b[i]) {
            res.push_back(1);
            flip(a[0]);
        }

        res.push_back(i + 1);
        if (rev) beg = beg - i;
        else beg = beg + i;
        rev ^= true;

        // cerr << a << '\n' << '\n';
    }

    char firstChar = a[0];
    if (rev) flip(firstChar);
    if (firstChar != b[0]) res.push_back(1);

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        vector<int> operations = solve(a, b);
        cout << operations.size();
        for (int o: operations) cout << " " << o;
        cout << '\n';
    }
}