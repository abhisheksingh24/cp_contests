#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        testCase();
    }
}

void insertInMap(int cur, int neigh, auto &res, auto &X) {
    if (cur > neigh) swap(cur, neigh);
    if (res.count(make_pair(cur, neigh))) return;
    int weight = max(1, abs(X[cur] - X[neigh]));
    res[make_pair(cur, neigh)] = weight;
}

map<pair<int, int>, int> solve(auto &X, auto &adj) {
    const int n = X.size();
    map<int, vector<int>> bef;
    vector<int> remain;
    for (int i = 1; i < n; i++) {
        if (X[i] < 0)
            bef[-X[i]].push_back(i);    
        else remain.push_back(X[i]);
    }
    sort(remain.begin(), remain.end());
    int seen = 1, latency = 0;
    
    // for (auto p: bef) {
    //     cerr << '\n' << p.first << ": ";
    //     for (int i: p.second) cerr << i << " ";
    //     cerr << '\n';
    // }

    // for (auto i: remain) cerr << i << " "; cerr << '\n';

    for (auto p: bef) {
        int cnt = p.first;
        vector<int> nodes = p.second;
        int req = cnt - seen;

        // cerr << "required " << req << '\n';

        if (req) latency = remain[req - 1] + 1;
        else latency++;

        // cerr << "latency = " << latency << '\n';

        for (int cur: nodes) X[cur] = latency;
        seen += nodes.size();
    }
    set<pair<int, int>> order;
    map<pair<int, int>, int> res;
    for (int i = 0; i < n; i++) order.emplace(X[i], i);
    for (auto p: order) {
        int cur = p.second;
        int latency = p.first;
        for (int neigh: adj[cur])
            insertInMap(cur, neigh, res, X);
    }
    return res;
}

void testCase() {
    int C, D;
    cin >> C >> D;
    vector<int> X(C, 0);
    for (int i = 1; i < C; i++)
        cin >> X[i];
    vector<vector<int>> adj(C);
    vector<pair<int, int>> edges;
    for (int i = 0; i < D; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    map<pair<int, int>, int> res = solve(X, adj);
    for (auto edge: edges)
        cout << res[edge] << " ";
    cout << '\n';   
}