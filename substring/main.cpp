#include <bits/stdc++.h>
using namespace std;
string a;
vector<vector<int>> g, l;
vector<int> d;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,cnt=0,ans=0; cin>>n>>m;
    cin>>a;
    g.resize(n); d.resize(n); l.resize(n, vector<int> (26));
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); d[v]++;
    }
    for (int i = 0; i < n; ++i) {
        if(d[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int r = q.front(); q.pop();
        l[r][a[r]-'a']++;
        for(int adj : g[r]) {
            for (int i = 0; i < 26; ++i) {
                l[adj][i] = max(l[adj][i], l[r][i]);
            }
            d[adj]--;
            if(d[adj]==0) q.push(adj);
        }
        cnt++;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 26; ++j)
            ans = max(ans, l[i][j]);
    if(cnt != n) cout << -1;
    else cout << ans;
}
