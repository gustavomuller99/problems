#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<int, bool> mp;
vector<int> d, sz;
int n,m,k;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
bool j(int u, int v) {
    u = g(u); v = g(v);
    if(u == v) return false;
    sz[u] += sz[v];
    d[v] = u;
    return sz[u] == k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>k;
    ll ans=0;
    d.resize(n); sz.resize(n);
    set<pair<ll, pair<int,int>>> e;
    for (int i = 0; i < k; ++i) {
        int x; cin>>x; x--; mp[x] = true;
    }
    for (int i = 0; i < n; ++i) { d[i] = i; if(mp[i]) sz[i]++; }
    for (int i = 0; i < m; ++i) {
        int u,v; ll c;cin>>u>>v>>c;u--,v--;
        e.insert({c, {u, v}});
    }
    for(auto r : e) {
        if(j(r.second.first, r.second.second)) { ans = r.first; break; }
    }
    for (int i = 0; i < k; ++i) cout << ans << " ";
}
