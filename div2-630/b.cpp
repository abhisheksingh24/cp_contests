#include<bits/stdc++.h>

using namespace std;

void pre(vector<int>& color) {
    int col = 1;
    for (int i = 2; i <= 1000; i++) if (!color[i]) {
        for (int j = i * i; j <= 1000; j += i) if (!color[i]){
            color[j] = col;
        } 
        col++;
    }
}

int reduce(vector<int>& v) {
    set<int> found(v.begin(), v.end());
    map<int, int> mapTo;
    int col = 1;
    for (int i: found) {
        mapTo[i] = col++;
    }
    for (int& i: v) i = mapTo[i];
    return found.size();
}

int main() {
    vector<int> color(1001, 0);
    pre(color);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i: a) {
            cin >> i;
            i = color[i];
        }
        int cntCol = reduce(a);
        cout << cntCol << endl;
        for (int& i: a) cout << i << " ";
        cout << endl;
    }
}