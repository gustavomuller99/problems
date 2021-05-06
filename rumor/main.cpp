#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<vector<int>> g;
vector<int> a;
vector<bool> vis;
int dfs(int n) {
    int r = a[n];
    vis[n] = true;
    for(int adj : g[n]) {
        if(!vis[adj]) {
            int k = dfs(adj);
            if(r > k) r = k;
        }
    }
    return r;
}
int main() {
    int n,m; cin>>n>>m;
    g.resize(n), a.resize(n), vis.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!vis[i]) ans += dfs(i);
    }
    cout << ans;
}
