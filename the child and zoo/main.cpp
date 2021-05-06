#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> d, sz;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int main() {
    ll n,m; cin>>n>>m; d.resize(n); sz.resize(n);
    double ans = 0;
    vector<int> a(n);
    vector<pair<ll, pair<int, int>>> e(m);
    for (int i = 0; i < n; ++i) cin>>a[i], d[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        e.push_back({min(a[u], a[v]), {u,v}});
    }
    sort(e.begin(), e.end(), greater<>());
    for (int i = 0; i < m; ++i) {
        auto r = e[i];
        int u = g(r.second.first), v = g(r.second.second);
        if(u != v) {
            ans += sz[u]*sz[v]*r.first;
            d[u] = v;
            sz[v] += sz[u];
        }
    }
    cout << setprecision(20) << ans * 2 / (n*(n-1));
}
