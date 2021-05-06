#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> c;
map<int, int> mp;
vector<bool> v;
int cc, h;
void dfs(int n) {
    v[n] = true;
    cc++;
    mp[c[n]]++;
    if(mp[c[n]] > h) h = mp[c[n]];
    for(int adj : g[n]) {
        if(!v[adj]) dfs(adj);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    g.resize(n); c.resize(n); v.resize(n);
    for (int i = 0; i < n; ++i) { cin >> c[i]; c[i]--; }
    for (int i = 0; i < m; ++i) {
        int x,y; cin>>x>>y; x--, y--;
        g[x].push_back(y); g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!v[i]) {
            cc = h = 0;
            mp.clear();
            dfs(i);
            ans += cc - h;
        }
    }
    cout << ans << "\n";
}
