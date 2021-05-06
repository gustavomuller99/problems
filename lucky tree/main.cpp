#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<vector<int>> t;
vector<ll> sz;
vector<bool> vis;
int dfs(int i, int f = -1) {
    int s = 0;
    vis[i] = true;
    for(int adj : t[i]) {
        if(adj == f) continue;
        s += dfs(adj, i);
    }
    return s+1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n; cin>>n;
    t.resize(n); vis.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; string c; cin>>u>>v>>c;u--,v--;
        bool a = false;
        for(char x : c) if(x != '4' && x != '7') a = true;
        if(a) {
            t[u].push_back(v), t[v].push_back(u);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        sz.push_back(dfs(i));
    }
    ll ans = 0;
    for(ll x : sz) {
        ans += x*(n-x)*(n-x-1);
    }
    cout << ans << "\n";
}
