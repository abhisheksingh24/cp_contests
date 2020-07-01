#include<bits/stdc++.h>

using namespace std;

#define int long long

void testCase();

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        testCase();
    }
}

vector<vector<int>> addToSubsets(vector<int> vec, int toAdd) {
    vector<vector<int>> result;
    for (int mask = 1; mask < (1 << 3); mask++) {
        vector<int> newVec = vec;
        for (int i = 0; i < 3; i++) {
            if ((1 << i) & mask) newVec[i] += toAdd;
        }
        result.push_back(newVec);
    }
    return result;
}

vector<vector<int>> mulToSubsets(vector<int> vec, int toMul) {
    vector<vector<int>> result;
    for (int mask = 1; mask < (1 << 3); mask++) {
        vector<int> newVec = vec;
        for (int i = 0; i < 3; i++) {
            if ((1 << i) & mask) newVec[i] *= toMul;
        }
        result.push_back(newVec);
    }
    return result;
}

vector<vector<int>> divToSubsets(vector<int> vec, int toDiv) {
    vector<vector<int>> result;
    if (toDiv == 0) return result;
    for (int mask = 1; mask < (1 << 3); mask++) {
        vector<int> newVec = vec;
        bool valid = true;
        for (int i = 0; i < 3; i++) if ((1 << i) & mask) {
            if (vec[i] % toDiv) valid = false;
            newVec[i] /= toDiv;
        }
        if (valid) result.push_back(newVec);
    }
    return result;
}

bool possible(int steps, vector<int> initial, vector<int> finl) {
    if (steps == 0) return initial == finl;

    set<int> adds, muls;
    for (int i = 0; i < 3; i++) if (initial[i] != finl[i]) {
        adds.insert(finl[i] - initial[i]);
        if (initial[i] != 0 && abs(finl[i]) % abs(initial[i]) == 0) muls.insert(finl[i] / initial[i]);
    }

    if (initial[1] != initial[0] && abs(finl[1] - finl[0]) % abs(initial[1] - initial[0]) == 0)
        muls.insert((finl[1] - finl[0]) / (initial[1] - initial[0]));

    for (int toAdd: adds) {
        auto initials = addToSubsets(initial, toAdd);
        for (auto newInitial: initials)
            if (possible(steps - 1, newInitial, finl)) 
                return true;
        auto finls = addToSubsets(finl, -toAdd);
        for (auto newFinl: finls) if (possible(steps - 1, initial, newFinl)) return true;
    }

    for (int toMul: muls) {
        auto initials = mulToSubsets(initial, toMul);
        for (auto newInitial: initials) if (possible(steps - 1, newInitial, finl)) return true;
        auto finls = divToSubsets(finl, toMul);
        for (auto newFinl: finls) if (possible(steps - 1, initial, newFinl)) return true;
    }

    return false;
}

void testCase() {
    int p, q, r, a, b, c;
    cin >> p >> q >> r;
    cin >> a >> b >> c;
    
    for (int i = 0; i < 3; i++) {
        if (possible(i, {p, q, r}, {a, b, c})) {
            cout << i << '\n';
            return;
        }
    }
    cout << 3 << '\n';
}