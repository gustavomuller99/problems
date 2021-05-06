#include <bits/stdc++.h>
using namespace std;
vector<set<int>> f;
vector<vector<vector<int>>> cap;
vector<vector<vector<int>>> cst;
vector<vector<int>> edges;
int src = 0, snk = 1, ans = 0;
void add(int u, int v, int ct, int cp) {
    f[u].insert(v), f[v].insert(u);
    cst[edges[u][v]][u][v] = ct; cst[edges[v][u]][v][u] = -ct;
    cap[edges[u][v]][u][v] = cp;
    edges[u][v]++; edges[v][u]++;
}
bool spfa() {
    vector<int> d(f.size(), INT_MAX);
    vector<pair<int,int>> p(f.size(), {-1, -1});
    vector<bool> iq(f.size());
    queue<int> q; q.push(src);
    d[src] = 0;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        iq[r] = false;
        for(int adj : f[r]) {
            for (int i = 0; i < edges[r][adj]; ++i) {
                if(cap[i][r][adj] > 0 && d[adj] > d[r] + cst[i][r][adj]) {
                    d[adj] = d[r] + cst[i][r][adj];
                    p[adj] = {r, i};
                    if(!iq[adj]) iq[adj] = true; q.push(adj);
                }
            }
        }
    }
    if(d[snk] == INT_MAX) return false;
    ans += d[snk];
    pair<int,int> cur = {snk, -1};
    while(cur.first != src) {
        cap[p[cur.first].second][p[cur.first].first][cur.first]--;
        cap[p[cur.first].second][cur.first][p[cur.first].first]++;
        cur = p[cur.first];
    }
    return true;
}
int main() {
    int n, q; cin>>n>>q;
    f.resize(2*n + 2);
    cap.resize(2*n + 2, vector<vector<int>> (2*n + 2, vector<int> (2*n + 2)));
    cst.resize(2*n + 2, vector<vector<int>> (2*n + 2, vector<int> (2*n + 2)));
    edges.resize(2*n + 2, vector<int> (2*n + 2));
    vector<pair<int,int>> a(n, {1,n});
    for (int i = 0; i < q; ++i) {
        int t,l,r,v; cin>>t>>l>>r>>v; l--,r--;
        if(t==1) for (int j = l; j <= r; j++) a[j].first = max(a[j].first, v);
        else for (int j = l; j <= r; j++) a[j].second = min(a[j].second, v);
    }
    for (int i = 0; i < n; ++i) if(a[i].first > a[i].second) { cout << -1; return 0; }
    for (int i = 1; i <= n; ++i) {
        add(src, i + 1, 0, 1);
        for (int j = a[i-1].first; j <= a[i-1].second; ++j) add(i + 1, n + j + 1, 0, 1);
        for (int j = 1; j <= n; ++j) add(n + i + 1, snk, 2*j - 1, 1);
    }
    while(true) if(!spfa()) break;
    cout << ans;
}
