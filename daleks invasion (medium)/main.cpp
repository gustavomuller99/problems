#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> d, tin, tout;
vector<vector<pair<int, ll>>> t, f(20);
vector<pair<pair<ll, int>, pair<int, int>>> e;
vector<pair<int, pair<int, int>>> q;
int timer = 0;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int is_a(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
void dfs(int i, int fth = 0, ll w = 0) {
    tin[i] = ++timer;
    f[0][i] = {fth, w};
    for(auto adj : t[i]) {
        if(adj.first == fth) continue;
        dfs(adj.first, i, adj.second);
    }
    tout[i] = ++timer;
}
int lca(int u, int v) {
    if(is_a(u, v)) return u;
    if(is_a(v, u)) return v;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(f[i][u].first, v)) u = f[i][u].first;
    }
    return f[0][u].first;
}
ll up(int u, int v) {
    ll r = 0;
    if(u == v) return 0;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(f[i][u].first, v)) r = max(r, f[i][u].second), u = f[i][u].first;
    }
    return max(r, f[0][u].second);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;cin>>n>>m;
    d.resize(n); t.resize(n); e.resize(m); tin.resize(n); tout.resize(n);
    for (int i = 0; i < 20; ++i) f[i].resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        cin>>e[i].second.first>>e[i].second.second>>e[i].first.first;
        e[i].first.second = i;
        e[i].second.first--, e[i].second.second--;
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        int u = g(e[i].second.first), v = g(e[i].second.second);
        if(u != v) {
            d[u] = v;
            t[u].push_back({v, e[i].first.first});
            t[v].push_back({u, e[i].first.first});
        } else q.push_back({e[i].first.second, {e[i].second.first, e[i].second.second}});
    }
    sort(q.begin(), q.end());
    dfs(0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = {f[i - 1][f[i - 1][j].first].first, max(f[i - 1][j].second, f[i - 1][f[i - 1][j].first].second)};
        }
    }
    for (int i = 0; i < q.size(); ++i) {
        int u = q[i].second.first, v = q[i].second.second;
        int anc = lca(u, v);
        cout << max(up(u, anc), up(v, anc)) << "\n";
    }
}
