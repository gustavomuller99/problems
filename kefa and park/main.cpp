#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> t;
vector<int> p;
int dfs(int i, int f = -1, int c = 0) {
    if(p[i]) c++;
    else c = 0;
    if(c > m) return 0;
    if(t[i].size() == 1 && i) return 1;
    int r = 0;
    for(int adj : t[i]) {
        if(adj == f) continue;
        r += dfs(adj, i, c);
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    t.resize(n); p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    cout << dfs(0) << "\n";
}
