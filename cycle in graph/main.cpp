#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int n,m,k,j=0,a1=-1,a2=-1;
map<int, int> mp;
vector<int> p;
void dfs(int u, int f = -1) {
    mp[u] = j+1; j++; p.push_back(u);
    for(int adj : g[u]) {
        if(adj == f) continue;
        if(mp[adj] && mp[u] - mp[adj] >= k && a1 == -1 && a2 == -1) a1 = mp[adj]-1, a2 = mp[u]-1;
        else if(!mp[adj]) dfs(adj, u);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>k;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(0);
    cout << a2 - a1 + 1 << "\n";
    for (int i = a1; i <= a2; i++) {
        cout << p[i]+1 << " ";
    }
}
