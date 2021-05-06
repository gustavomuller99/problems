#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<vector<int>> g;
vector<int> vis, topo;
bool ans = true;
void dfs(int i) {
    vis[i] = 1;
    for(int adj : g[i]) {
        if(vis[adj] == 2) continue;
        if(vis[adj] == 1) { ans = false; continue; }
        dfs(adj);
    }
    vis[i] = 2;
    topo.push_back(i);
}
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    g.resize(n+1); vis.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        string p; cin>>p;
        mp[p] = i;
    }
    for (int i = 0; i < m; ++i) {
        string a; int pos; cin>>a>>pos;
        bool ps = false;
        vector<int> edges;
        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l < 2; ++l) {
                for (int o = 0; o < 2; ++o) {
                    for (int p = 0; p < 2; ++p) {
                        string c = a;
                        if(j) c[0] = '_'; if(l && k > 1) c[1] = '_'; if(o && k > 2) c[2] = '_'; if(p && k > 3) c[3] = '_';
                        int e = mp[c];
                        if(e) {
                            if(e == pos) ps = true;
                            edges.push_back(e);
                        }
                    }
                }
            }
        }
        ans &= ps;
        for(int x : edges) {
            if(x == pos) continue;
            g[pos].push_back(x);
        }
    }
    if(!ans) cout << "NO\n";
    else {
        for (int i = 1; i <= n; ++i) if(vis[i] == 0) dfs(i);
        if(!ans) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto i = topo.rbegin(); i != topo.rend(); ++i) cout << *i << " ";
        }
    }
}
