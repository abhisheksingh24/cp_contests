#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<vector<int> > children;

void fillChildren(int cur, int par = -1) {
    for (int ch: adj[cur]) if (ch != par) {
        children[cur].push_back(ch);
        fillChildren(ch, cur);
    }
}

int onlyChild(int cur, int par) {
    for (int ch: adj[cur]) if (ch != par) return ch;
    return -1;
}

pair<int, bool> solveMin(int cur) {
    int res = 1;
    bool even = false, odd = false;
    for (int ch: children[cur]) {
        int chh = ch;
        int depth = 1;
        while (children[chh].size() == 1) chh = children[chh][0], depth++;
        pair<int, bool> further = solveMin(chh);
        if (children[chh].size() > 1 && !further.second) depth++;
        //cerr << cur << " - " << chh << ": " << depth << '\n';
        if (depth % 2) odd = true;
        else even = true;
        res = max(res, further.first);
    }
    if (even && odd) res = 3;
    //cerr << cur << ": " << res << ": " << even << " " << odd << '\n';
    return {res, even && !odd};
}

int solveMax(int cur) {
    int res = 0;
    bool one = false;
    for (int ch: children[cur]) {
        if (children[ch].empty()) {
            one = true;
            continue;
        }
        int chh = ch;
        int depth = 1;
        while (children[chh].size() == 1) chh = children[chh][0], depth++;
        res += depth;
        res += solveMax(chh);
    }
    //cerr << cur + 1 << ": " << res + one << '\n'; 
    return res + one;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    children.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    if (adj[root].size() == 1) root = adj[root][0];
    fillChildren(root);
    cout << solveMin(root).first << " " << solveMax(root) << '\n';
}