#include <bits/stdc++.h>
using namespace std;
vector<int> vis, d;
vector<pair<int,int>> dp;
vector<vector<pair<int, int>>> g;
void dfs(int n) {
    vis[n] = true;
    for(auto adj : g[n]) {
        if(!vis[adj.first]) dfs(adj.first);
    }
    d.push_back(n);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,s,ans=INT_MAX; cin>>n>>m;
    vector<bool> in(n); g.resize(n); vis.resize(n); dp.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back({v, i});
        in[v] = true;
    }
    for (int i = 0; i < n; ++i) if(in[i] == false) s = i;
    dfs(s);
    for (int i = d.size()-1; i >= 0; --i) {
        if(dp[d[i]].first == n-1) ans = dp[d[i]].second;
        for(auto adj : g[d[i]]) {
            if(dp[d[i]].first + 1 > dp[adj.first].first) {
                dp[adj.first].first = dp[d[i]].first + 1;
                dp[adj.first].second = max(dp[d[i]].second, adj.second);
            }
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans + 1;
}