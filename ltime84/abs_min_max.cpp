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

long long solve(auto &A) {
    const int n = A.size();
    vector<int> inc, dec;
    map<int, int> both;
    long long res = 0;
    for (int i = 0; i < n; i++) {

        while (!inc.empty() && A[i] < A[inc.back()]) {
            both[inc.back()]--;
            if (both[inc.back()] == 0) both.erase(inc.back());
            inc.pop_back();
        }
        inc.push_back(i);

        while (!dec.empty() && A[i] > A[dec.back()]) {
            both[dec.back()]--;
            if (both[dec.back()] == 0) both.erase(dec.back());
            dec.pop_back();
        }
        dec.push_back(i);

        both[i] = 2;

        res += both.size();
    }
    return res;
}

void testCase() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A) cin >> i;
    cout << solve(A) << '\n';
}