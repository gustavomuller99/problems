#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    vector<ll> d(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        for(int adj : g[i]) {
            if(adj < i) {
                d[i] = max(d[i], d[adj] + 1);
            }
        }
        ans = max(ans, d[i] * (ll) g[i].size());
    }
    cout << ans;
}
