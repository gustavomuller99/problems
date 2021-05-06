#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> p, d;
vector<bool> vis;
set<int> c;
int s = -1, e = -1;
void dfs1(int i = 0, int f = 0) {
    vis[i] = true;
    for(int adj : g[i]) {
        if(adj == f) continue;
        if(!vis[adj]) {
            p[adj] = i;
            dfs1(adj, i);
        } else if(s == e) {
            e = i; s = adj;
        }
    }
}
void dfs2(int i, int dist = 0) {
    if(c.count(i)) dist = 0;
    d[i] = dist;
    vis[i] = true;
    for(int adj : g[i]) {
        if(!vis[adj]) dfs2(adj, dist + 1);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; g.resize(n); p.resize(n); vis.resize(n); d.resize(n);
    for (int i = 0; i < n; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1();
    while(e != s) { c.insert(e); e = p[e]; }
    c.insert(s);
    vis = vector<bool> (n);
    dfs2(s);
    for(int k : d) cout << k << " ";
}
