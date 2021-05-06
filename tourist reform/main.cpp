#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
set<pair<int, int>> b, e;
vector<bool> v;
vector<int> tin, low;
int t = 0;
void dfs1(int n, int p = -1) {
    v[n] = true;
    tin[n] = low[n] = t++;
    for(int k : g[n]) {
        if(k == p) continue;
        if(v[k]) low[n] = min(low[n], tin[k]);
        else {
            dfs1(k, n);
            low[n] = min(low[n], low[k]);
            if(low[k] > tin[n]) {
                b.insert({n, k});
            }
        }
    }
}
int dfs2(int n, int p = -1) {
    v[n] = true;
    int r = 1;
    for(int k : g[n]) {
        if(k == p) continue;
        if(!v[k] && !b.count({k, n}) && !b.count({n, k})) r += dfs2(k, n);
    }
    return r;
}
void dfs3(int n, int p = -1) {
    v[n] = true;
    for(int k : g[n]) {
        if(k == p) continue;
        if(b.count({n, k}) || b.count({k, n})) e.insert({k, n});
        else if(!e.count({n, k}) && !e.count({k, n})) e.insert({n, k});
        if(!v[k]) dfs3(k, n);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    v.resize(n + 1);
    tin.resize(n + 1, -1);
    low.resize(n + 1, -1);
    vector<pair<int, int>> in(m);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        in[i] = {x, y};
    }
    dfs1(1);
    v.assign(n + 1, false);
    int mx = 0, mi = 0;
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) {
            int r = dfs2(i);
            if(r > mx) { mx = r; mi = i; }
        }
    }
    cout << mx << "\n";
    v.assign(n + 1, false);
    dfs3(mi);
    for(auto k : in) {
        if(e.count({k.first, k.second})) cout << k.first << " " << k.second;
        else cout << k.second << " " << k.first;
        cout << "\n";
    }
}
