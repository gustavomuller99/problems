#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
vector<vector<int>> g, b, sh;
vector<bool> vis;
void bfs(int p) {
    queue<pair<int, int>> q;
    vis = vector<bool> (n);
    for (int i = 0; i < b[p].size(); ++i) q.push({b[p][i], 0});
    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        vis[r.first] = true;
        sh[r.first][p] = min(sh[r.first][p], r.second);
        for(int adj : g[r.first]) {
            if(vis[adj]) continue;
            q.push({adj, r.second + 1});
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k>>s;
    b.resize(k); g.resize(n);
    sh.resize(n, vector<int> (k, INT_MAX));
    for (int i = 0; i < n; ++i) { int u; cin>>u; u--; b[u].push_back(i); }
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v; u--, v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 0; i < k; ++i) bfs(i);
    for (int i = 0; i < n; ++i) {
        sort(sh[i].begin(), sh[i].end());
        int ans = 0;
        for (int j = 0; j < s; ++j) ans += sh[i][j];
        cout << ans << " ";
    }
}
