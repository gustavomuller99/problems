#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> g;
vector<int> c, sz;
void dfs(int u, int f = -1) {
    sz[u] = 1;
    bool ct = true;
    for(int adj : g[u]) {
        if(adj == f) continue;
        dfs(adj, u);
        if(sz[adj] > n/2) ct = false;
        sz[u] += sz[adj];
    }
    if(n - sz[u] > n/2) ct = false;
    if(ct) c.push_back(u);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        g = vector<vector<int>> (n), c = vector<int> (), sz = vector<int> (n);
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin>>u>>v; u--, v--;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(0);
        if(c.size() == 1) cout << c[0] + 1 << " " << g[c[0]][0] + 1 << "\n" << c[0] + 1 << " " << g[c[0]][0] + 1 << "\n";
        else {
            int k = (g[c[1]][0] == c[0] ? g[c[1]][1] : g[c[1]][0]);
            cout << c[1] + 1 << " " << k + 1 << "\n" << c[0] + 1 << " " << k + 1 << "\n";
        }
    }
}
