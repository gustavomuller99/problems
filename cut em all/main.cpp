#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> s;
int ans = 0;
int dfs1(int n = 0, int f = -1) {
    int sz = 1;
    for(int adj : t[n]) {
        if(adj == f) continue;
        sz += dfs1(adj, n);
    }
    s[n] = sz;
    return sz;
}
int dfs2(int n = 0, int f = -1, int sz = s[0]) {
    for(int adj : t[n]) {
        if(adj == f) continue;
        if((s[adj] % 2 == 0) && ((sz - s[adj]) % 2 == 0)) {
            ans++;
            sz -= s[adj];
            dfs2(adj, n, sz - s[adj]);
        } else {
            sz = dfs2(adj, n, sz);
        }
    }
    return sz;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n); s.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[u].push_back(v); t[v].push_back(u);
    }
    if(n % 2) cout << -1;
    else {
        dfs1();
        dfs2();
        cout << ans;
    }
}
