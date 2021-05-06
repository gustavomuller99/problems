#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
pair<int, int> dfs(int n, int f = -1) {
    pair<int, int> r = {n, 1};
    for(int adj : t[n]) {
        if(adj == f) continue;
        auto rt = dfs(adj, n);
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
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    auto a = dfs(0);
    auto b = dfs(a.first);
    cout << (b.second - 1) * 3 << "\n";
}
