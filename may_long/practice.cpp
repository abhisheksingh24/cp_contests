#include<bits/stdc++.h> 

using namespace std;

void threeWaySwap(auto& vec, auto& moves) {
    swap(vec[moves[0]], vec[moves[1]]);
    swap(vec[moves[0]], vec[moves[2]]);
}

int main() {
    vector<int> vec = {2, 3, 4, 1};
    vector<vector<int> > moves;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (i == j || i == k || j == k) continue;
                moves.push_back({i, j, k});
            }
        }
    }
    vector<int> sorted = {1, 2, 3, 4};
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < moves.size(); j++) {
            for (int k: moves[i]) cout << k << " "; cout << '\n';
            for (int k: moves[j]) cout << k << " "; cout << '\n';
            auto vecc = vec;
            threeWaySwap(vecc, moves[i]);
            threeWaySwap(vecc, moves[j]);
            for (int k: vecc) cout << k << " "; cout << '\n';
            if (vecc == sorted) cout << "your logic flawed\n";
        }
    }
    cout << "not possible\n";
}