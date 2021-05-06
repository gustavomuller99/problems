#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> c;
vector<bool> vis;
bool ans = true;
void dfs(int n, int p) {
    vis[n] = true;
    c[n] = p;
    for(int adj : g[n]) {
        if(vis[adj]) {
            if(c[adj] == c[n]) ans = false;
        } else {
            dfs(adj, (p == 1 ? 2 : 1));
        }
    }
}
int main() {
    int n,m; cin>>n>>m;
    g.resize(n), c.resize(n); vis.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) if(!vis[i]) dfs(i, 1);
    if(!ans) cout << -1;
    else {
        vector<vector<int>> p(2);
        for (int i = 0; i < n; ++i) p[c[i]-1].push_back(i);
        cout << p[0].size() << "\n";
        for(int k : p[0]) cout << k+1 << " "; cout << "\n";
        cout << p[1].size() << "\n";
        for(int k : p[1]) cout << k+1 << " ";
    }
}
