#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis, c;
int dfs(int i, int cc) {
    cc++; vis[i] = true;
    for(int adj : g[i]) {
        if(!vis[adj]) cc = dfs(adj, cc);
    }
    c[i] = cc;
    return cc;
}
int main() {
    int n, m; cin>>n>>m;
    g.resize(n); vis.resize(n); c.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) if(!vis[i]) dfs(i, 0);
    for (int i = 0; i < n; ++i) if(g[i].size() != c[i] - 1) ans = false;
    if(ans) cout << "YES";
    else cout << "NO";
}
