#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> d;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    g.resize(51*n);
    d.resize(51*n, INT_MAX);
    d[0] = 0;
    for (int i = 0; i < m; ++i) {
        int u,v,w; cin>>u>>v>>w; u--,v--;
        g[u*51].push_back({0,v*51+w});
        g[v*51].push_back({0,u*51+w});
        for (int j = 1; j <= 50; ++j) {
            g[u*51+j].push_back({(j+w)*(j+w), v*51});
            g[v*51+j].push_back({(j+w)*(j+w), u*51});
        }
    }
    priority_queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        auto r = q.top(); q.pop();
        r.first = -r.first;
        if(d[r.second] == r.first) {
            for (auto adj : g[r.second]) {
                if (d[adj.second] > r.first + adj.first) {
                    d[adj.second] = r.first + adj.first;
                    q.push({-d[adj.second], adj.second});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << (d[i*51] == INT_MAX ? -1 : d[i*51]) << " ";
}