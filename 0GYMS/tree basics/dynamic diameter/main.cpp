#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<vector<int>> d(2);
pair<int, int> dfs(int n, int i, int dist = 0, int f = -1) {
    d[i][n] = dist;
    pair<int, int> r = {n, 1};
    for(int adj : t[n]) {
        if(adj == f) continue;
        auto rt = dfs(adj, i, dist + 1, n);
        if(rt.second >= r.second) {
            r.first = rt.first;
            r.second = rt.second + 1;
        }
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; t.resize(n);
    d[0].resize(n); d[1].resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    auto a = dfs(0, 0);
    auto b = dfs(a.first, 0);
    auto _ = dfs(b.first, 1);
    for (int i = 0; i < n; ++i) {
        cout << max(b.second - 1, max(d[0][i] + 1, d[1][i] + 1)) << "\n";
    }
}
