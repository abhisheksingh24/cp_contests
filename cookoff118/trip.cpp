#include<bits/stdc++.h>

using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void testCase();

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
}

vector<vector<int>> P;

void dfs(int cur, int par, auto &adj, auto &A, auto &rinc, auto &rdec, auto &depth) {
    for (int ch: adj[cur]) if (ch != par) {
        P[0][ch] = cur;
        depth[ch] = depth[cur] + 1;
        if (A[cur] > A[ch]) rinc[ch] = rinc[cur] + 1;
        if (A[cur] < A[ch]) rdec[ch] = rdec[cur] + 1;
        dfs(ch, cur, adj, A, rinc, rdec, depth);
    }
}

int dist(int u, int v, auto &depth) {
    return abs(depth[u] - depth[v]);
}

void build(int n){
    for(int i = 1; i < 31; ++i){
        for(int j = 0; j < n; j++){
            int x = P[i-1][j];
            P[i][j] = P[i-1][x];
        }
    }
}

int power(int b, int e) {
    if (e == 0) return 1;
    int res = power(b * b, e / 2);
    if (e % 2) return b * res;
    return res;
}

int parent(int x , int k){
    int kk = power(2, log2(k));
    for(int i = log2(k); i>=0; i--, kk /= 2) {
        if (kk <= k) {
            x = P[i][x];
            k-= kk;
        }
    }
    return x;
}

void testCase() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> A(n), rinc(n), rdec(n), depth(n);
    for (int &i: A) cin >> i;
    LCA L(adj);
    P.assign(31, vector<int>(n, 0));
    dfs(0, -1, adj, A, rinc, rdec, depth);
    build(n);
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int l = L.lca(x, y);
        if (l == x) {
            int reach = rinc[y] + rdec[parent(y, rinc[y])];
            if (reach >= dist(x, y, depth)) {
                cout << 1;
            } else cout << 0;

        } else if (l == y) {
            int reach = rinc[x] + rdec[parent(x, rinc[x])];
            if (reach >= dist(x, y, depth)) {
                cout << 1;
            } else cout << 0;
        } else {
            int reach = rinc[x];
            if (reach >= dist(x, l, depth)) {
                int reach2 = rinc[y] + rdec[parent(y, rinc[y])];
                if (reach2 >= dist(y, l, depth)) {
                    cout << 1;
                } else cout << 0;
            } else {
                reach = rinc[x] + rdec[parent(x, rinc[x])];
                int reach2 = rinc[y];
                if (reach >= dist(x, l, depth) && reach2 >= dist(y, l, depth)) {
                    cout << 1;
                } else cout << 0;
            }
        }
    }
    cout << '\n';
}