#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<vector<int>> f;
vector<int> tin, tout, d;
int timer = 0;
bool is_a(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
void dfs(int i = 0, int fth = 0, int dth = 0) {
    tin[i] = ++timer;
    f[0][i] = fth;
    d[i] = dth;
    for(int adj : t[i]) {
        if(adj == fth) continue;
        dfs(adj, i, dth + 1);
    }
    tout[i] = ++timer;
}
int lca(int u, int v) {
    if(is_a(u, v)) return u;
    if(is_a(v, u)) return v;
    for (int i = 19; i >= 0; --i) if(!is_a(f[i][u], v)) u = f[i][u];
    return f[0][u];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    t.resize(n); tin.resize(n); tout.resize(n); f.resize(20); d.resize(n);
    vector<int> ans;
    for (int i = 0; i < 20; ++i) f[i].resize(n);
    for (int i = 1; i <= n-1; ++i) {
        int u; cin>>u; u--;
        t[i].push_back(u); t[u].push_back(i);
    }
    dfs();
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) f[i][j] = f[i-1][f[i-1][j]];
    }
    int a = 0, b = 0, da = 0;
    for (int i = 1; i < n; ++i) {
        int anc1 = lca(a, i), d1 = d[a] + d[i] - 2*d[anc1];
        int anc2 = lca(b, i), d2 = d[b] + d[i] - 2*d[anc2];
        if(d1 > da && d1 > d2) ans.push_back(d1), b = i, da = d1;
        else if(d2 > da) ans.push_back(d2), a = i, da = d2;
        else ans.push_back(da);
    }
    for(int k : ans) cout << k << " ";
}
