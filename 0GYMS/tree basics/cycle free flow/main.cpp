#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int n, m, q, timer = 0;
vector<int> tin, tout;
vector<vector<pair<int, ll>>> t, b(20);
void dfs(int i, int f = 0, ll w = LONG_LONG_MAX) {
    tin[i] = ++timer;
    b[0][i] = {f, w};
    for(auto adj : t[i]) {
        if(adj.first == f) continue;
        dfs(adj.first, i, adj.second);
    }
    tout[i] = ++timer;
}
bool is_a(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v) {
    if(is_a(u, v)) return u;
    if(is_a(v, u)) return v;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(b[i][u].first, v)) u = b[i][u].first;
    }
    return b[0][u].first;
}
ll up(int u, int h) {
    if(u == h) return LLONG_MAX;
    ll r = LLONG_MAX;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(b[i][u].first, h)) { r = min(r, b[i][u].second); u = b[i][u].first;  }
    }
    return min(r, b[0][u].second);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m; t.resize(n);
    tin.resize(n); tout.resize(n);
    for (int i = 0; i < 20; ++i) b[i].resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        t[u].push_back({v, w});
        t[v].push_back({u, w});
    }
    dfs(0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) b[i][j] = {b[i-1][b[i-1][j].first].first, min(b[i-1][j].second, b[i-1][b[i-1][j].first].second)};
    }
    cin >> q; while(q--) {
        int u, v; cin >> u >> v; u--, v--;
        int anc = lca(u, v);
        cout << min(up(u, anc), up(v, anc)) << "\n";
    }
}
