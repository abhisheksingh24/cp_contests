#include<bits/stdc++.h>

using namespace std;

void testCase();

int main() {
    //cin.tie(nullptr) -> sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        testCase();
    }
}

void printAnswer(vector<int>& cycle, int k) {
    cerr << "cycle " << k << '\n';
    for (int i: cycle) cerr << i << " "; cerr << '\n';
    if (cycle.size() <= k) {
        cout << 2 << '\n';
        cout << cycle.size() << '\n';
        for (int node: cycle) cout << node + 1 << " ";
        cout << '\n';

    } else {
        cout << 1 << '\n';
        for (int i = 0; i < (k + 1) / 2; i++)
            cout << cycle[2 * i] + 1 << " ";
        cout << '\n';
    }
}

void printAnswer(vector<int>& par, auto& adj, int n, int k) {
    vector<int> leaves;
    int root = 0;
    for (int i = 1; i < n; i++) if (adj[i].size() == 1) leaves.push_back(i);

    vector<int> nodes;
    int incRoot = 1;
    for (int leaf: leaves) {
        int inc = 1;
        for (int cur = leaf; cur != root; cur = par[cur], inc ^= 1) {
            if (inc) nodes.push_back(cur);
        }
        incRoot &= inc;
    }
    if (incRoot) nodes.push_back(root);

    assert(nodes.size() >= (k + 1) / 2);

    cout << 1 << '\n';
    for (int i = 0; i < (k + 1) / 2; i++)
        cout << nodes[i] + 1 << " ";
    cout << '\n';
}

int findLca(int u, int v, vector<int>& par) {
    set<int> seen;
    for (int cur = u; cur != -1; cur = par[cur])
        seen.insert(cur);
    for (int cur = v; cur != -1; cur = par[cur])
        if (seen.count(cur)) return cur;
    return -1;
}

pair<int, int> dfs(int cur, int parent, auto& adj, auto& par, auto& seen) {
    seen[cur] = true;
    for (int child: adj[cur]) if (child != parent) {
        if (seen[child]) return {cur, child};
        par[child] = cur;
        return dfs(child, cur, adj, par, seen);
    }
    return {-1, -1};
}

pair<int, int> findCycle(auto& adj, vector<int>& par) {
    const int n = adj.size();
    vector<bool> seen(n, false);
    return dfs(0, -1, adj, par, seen);
    
}

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> seen(n, false);
    vector<vector<int> > adj(n);
    vector<int> par(n, -1);
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int, int> cycleLeaves = findCycle(adj, par);

    if (cycleLeaves == make_pair(-1, -1)) {
        printAnswer(par, adj, n, k);

    } else {
        int u = cycleLeaves.first;
        int v = cycleLeaves.second;
        int lca = findLca(u, v, par);
        cerr << "lca = " << lca << " " << u << " " << v << '\n';
        assert(lca != -1);
        vector<int> cycle;
        for (int cur = u; cur != lca; cur = par[cur])
            cycle.push_back(cur);
        cycle.push_back(lca);
        reverse(cycle.begin(), cycle.end());
        for (int cur = v; cur != lca; cur = par[cur])
            cycle.push_back(lca);
        printAnswer(cycle, k);
    }
}