#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> d;
vector<vector<pair<int,ll>>> g;
int n,m,k;
void dj(int b) {
    set<pair<ll,int>> s;
    d = vector<ll> (n+1, LONG_LONG_MAX);
    vector<int> v(n+1);
    s.insert({0,b});
    d[b] = 0;
    while(!s.empty()) {
        auto r = *s.begin(); s.erase(s.begin());
        v[r.second] = 1;
        for(auto adj : g[r.second]) {
            if(v[adj.first]) continue;
            if(d[adj.first] > adj.second + d[r.second]) {
                s.erase({d[adj.first], adj.first});
                d[adj.first] = adj.second + d[r.second];
                s.insert({d[adj.first], adj.first});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k;
    g.resize(n+1); vector<int> b(k);
    for (int i = 0; i < n; ++i) {
        ll w; cin>>w;
        g[0].push_back({i+1, w});
        g[i+1].push_back({0, w});
    }
    for (int i = 0; i < m; ++i) {
        int u,v; ll w; cin>>u>>v>>w;
        g[u].push_back({v,w}), g[v].push_back({u,w});
    }
    for (int i = 0; i < k; ++i) cin>>b[i];
    for (int i = 0; i < k; ++i) {
        dj(b[i]);
        for (int j = 1; j <= n; ++j) cout<<d[j]<<" ";
        cout<<"\n";
    }
}
