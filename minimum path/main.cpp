#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m; cin>>n>>m;
    vector<vector<pair<int, ll>>> g(n);
    vector<ll> d(n, LLONG_MAX);
    for (int i = 0; i < m; ++i) {
        int u,v; ll c; cin>>u>>v>>c; u--,v--;
        g[u].push_back({v, c}), g[v].push_back({u, c});
    }
    priority_queue<pair<pair<ll, int>, pair<ll, ll>>> q; q.push({{0,0}, {LLONG_MAX,LLONG_MIN}});
    while(!q.empty()) {
        auto r = q.top(); q.pop();
        int u = r.first.second;
        ll c = -r.first.first, mn = r.second.first, mx = r.second.second;
        if(c > d[u]) continue;
        d[u] = c;
        for (auto adj : g[u]) {
            ll dist = c + (mx == LLONG_MIN ? 0 : mx) - (mn == LLONG_MAX ? 0 : mn);
            if(dist - max(mx, adj.second) + min(mn, adj.second) + adj.second <= d[adj.first])
                q.push({{-(dist - max(mx, adj.second) + min(mn, adj.second) + adj.second), adj.first}, {min(mn, adj.second), max(mx, adj.second)}});
        }
    }
    for (ll dist : d) cout << dist << " ";
}
