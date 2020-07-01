#include<bits/stdc++.h>

using namespace std;

vector<bool> safe;
vector<int> d;

long long bfs(int n, int g, int r) {
    vector<long long> dist(n + 1, -1);
    queue<int> toVisit;
    for (int i = 1; i < g; i++) {
        if (n - i >= 0 && safe[n - i]) {
            toVisit.push(n - i);
            dist[n - i] = i;
        }
    }
    while (!toVisit.empty()) {
        int cur =  toVisit.front();
        toVisit.pop();
        set<pair<int, int> > nxt = {{cur, g}};
        while (!nxt.empty()) {
            auto p = *nxt.begin();
            nxt.erase(nxt.begin());
            if (p.second == 0 && dist[p.first] == -1) {
                toVisit.push(p.first);
                dist[p.first] = dist[cur] + g + r;
            }
            int m = p.first;
            auto l = lower_bound(d.begin(), d.end(), m);
            auto r = upper_bound(d.begin(), d.end(), m);
            int rem = p.second;
            if (l != d.begin()) {
                --l;
                int req = m - (*l);
                if (req <= rem) nxt.emplace((*l), rem - req);
            }
            if (r != d.end()) {
                int req = (*r) - m;
                if (req <= rem) nxt.emplace(*r, rem - req);
            }
        }
    }
    return dist[0];
}

int main() {
    int n, m;
    cin >> n >> m;
    safe.resize(n + 1, false);
    d.resize(m);
    for (int& i: d) {
        cin >> i;
        safe[i] = true;
    }
    sort(d.begin(), d.end());
    int g, r;
    cin >> g >> r;
    cout << bfs(n, g, r) << endl;
}