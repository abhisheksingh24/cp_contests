#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << '\n';
            continue;
        }
        if ((n - 1) % 9 == 0) {
            n--;
            cout << 9;
        }
        while (--n) cout << 2;
        cout << 9 << '\n'; 
    }
}