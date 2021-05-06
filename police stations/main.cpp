#include <bits/stdc++.h>
using namespace std;
int n, k, d;
set<int> p, ans;
map<pair<int, int>, int> mp;
vector<vector<int>> t;
vector<bool> vis;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k >> d;
    t.resize(n + 1); vis.resize(n + 1);
    queue<int> q;
    for (int i = 0; i < k; ++i) { int ps; cin >> ps; q.push(ps); vis[ps] = true; }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
        mp[{u, v}] = i; mp[{v, u}] = i;
        ans.insert(i);
    }
    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        for(int adj : t[r]) {
            if(vis[adj]) continue;
            q.push(adj);
            ans.erase(mp[{r, adj}]);
            vis[adj] = true;
        }
    }
    cout << ans.size() << "\n";
    for(int del : ans) {
        cout << del << " ";
    } cout << "\n";
}
