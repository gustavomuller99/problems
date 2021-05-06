#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t, f(20);
vector<int> d, tin, tout;
int timer = 0, n, q;
bool is_a(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
void dfs(int i, int dth = 0, int fth = 0) {
    tin[i] = ++timer;
    f[0][i] = fth; d[i] = dth;
    for(int adj : t[i]) {
        if(adj == fth) continue;
        dfs(adj, dth + 1, i);
    }
    tout[i] = ++timer;
}
int lca(int u, int v) {
    if(is_a(u, v)) return u;
    if(is_a(v, u)) return v;
    for(int i = 19; i >= 0; --i)
        if(!is_a(f[i][u], v)) u = f[i][u];
    return f[0][u];
}
int up(int u, int h) {
    for (int i = 19; i >= 0 ; --i) {
        if(1 << i <= h) { u = f[i][u]; h -= 1 << i; }
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; t.resize(n); tin.resize(n); tout.resize(n); d.resize(n);
    for(int i = 0; i < 20; ++i) f[i].resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = f[i-1][f[i-1][j]];
        }
    }
    cin >> q;
    while(q--) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        int anc = lca(a, b);
        if(c >= d[a] + d[b] - 2*d[anc]) cout << b + 1 << "\n";
        else if(c < d[a] - d[anc]) cout << up(a, c) + 1 << "\n";
        else cout << up(b, d[b] - d[anc] - (c - (d[a] - d[anc]))) + 1 << "\n";
    }
}
