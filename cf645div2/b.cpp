#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    int t;
    cin >> t;
    while (t--) testCase();
}

void testCase() {
    int n;
    cin >> n;
    multiset<int> remain;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        remain.insert(temp);
    }
    while (true) {
        auto it = remain.lower_bound(remain.size() + 1);
        if (it == remain.end()) break;
        remain.erase(it);
    }
    cout << 1 + remain.size() << '\n';
}