#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<pair<pair<ll, int>,pair<int,int>>> e;
vector<vector<pair<int, ll>>> t, f(20);
vector<int> d, tin, tout;
int timer = 0;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
bool is_a(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int lca(int u, int v) {
    if(is_a(u,v)) return u;
    if(is_a(v,u)) return v;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(f[i][u].first, v)) u = f[i][u].first;
    }
    return f[0][u].first;
}
ll up(int u, int v) {
    if(u == v) return 0;
    ll r = 0;
    for (int i = 19; i >= 0; --i) {
        if(!is_a(f[i][u].first, v)) r = max(r, f[i][u].second), u = f[i][u].first;
    }
    r = max(r, f[0][u].second);
    return r;
}
void dfs(int i, int fth = 0, ll w = 0) {
    timer++;
    tin[i] = timer;
    f[0][i] = {fth, w};
    for(auto adj : t[i]) {
        if(adj.first == fth) continue;
        dfs(adj.first, i, adj.second);
    }
    timer++;
    tout[i] = timer;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m; cin>>n>>m;
    ll sum = 0;
    d.resize(n); tin.resize(n); tout.resize(n); t.resize(n);
    for (int i = 0; i < 20; ++i) f[i].resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        ll u,v,w; cin>>u>>v>>w; u--,v--;
        e.push_back({{w, i}, {u,v}});
    } sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        int u = g(e[i].second.first), v = g(e[i].second.second);
        ll w = e[i].first.first;
        if(u != v) {
            d[u] = v;
            sum += w;
            t[e[i].second.first].push_back({e[i].second.second, w}); t[e[i].second.second].push_back({e[i].second.first, w});
        }
    }
    dfs(0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = {f[i-1][f[i-1][j].first].first, max(f[i-1][f[i-1][j].first].second, f[i-1][j].second)};
        }
    }
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int u = e[i].second.first, v = e[i].second.second;
        ll w = e[i].first.first;
        int anc = lca(u,v);
        ll mx = max(up(u, anc), up(v, anc));
        ans[e[i].first.second] = sum - mx + w;
    }
    for(ll x : ans) cout << x << "\n";
}
