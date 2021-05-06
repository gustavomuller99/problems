#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
pair<int, int> dfs(int n, int f = -1) {
    int r = 0;
    int v = n;
    for (int i = 0; i < g[n].size(); ++i) {
        if(g[n][i] != f) {
            pair<int, int> k;
            k = dfs(g[n][i], n);
            if(k.second > r) {
                r = k.second;
                v = k.first;
            }
        }
    }

    return make_pair(v, r + 1);
}
int main() {
    int n, m; cin>>n>>m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pair<int, int> r = dfs(0);
    r = dfs(r.first);
    cout << r.second - 1 << endl;
}
