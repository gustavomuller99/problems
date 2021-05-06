#include <bits/stdc++.h>
using namespace std;
int n,m,k,w;
vector<vector<string>> s;
vector<vector<pair<int,int>>> g;
int cc(int u, int v) {
    int c = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) c += s[u][i][j] != s[v][i][j];
    return c*w;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k >> w;
    s.resize(k + 1, vector<string>(n));
    g.resize(k + 1);
    vector<pair<int, int>> e;
    set<int> v;
    int ans = 0;
    for (int i = 1; i <= k; ++i) for (int j = 0; j < n; ++j) cin >> s[i][j];
    for (int i = 1; i <= k; ++i) {
        g[i].push_back({n * m, 0});
        g[0].push_back({n * m, i});
        for (int j = i + 1; j <= k; ++j) {
            int c = cc(i, j);
            g[i].push_back({c, j});
            g[j].push_back({c, i});
        }
    }
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto r = q.top();
        q.pop();
        if (v.count(r.second.second)) continue;
        e.emplace_back(r.second.second, r.second.first);
        v.insert(r.second.second);
        ans += -r.first;
        for (auto adj : g[r.second.second]) {
            q.push({-adj.first, {r.second.second, adj.second}});
        }
    }
    cout << ans << "\n";
    for (int i = 1; i < e.size(); i++) cout << e[i].first << " " << e[i].second << "\n";
}
