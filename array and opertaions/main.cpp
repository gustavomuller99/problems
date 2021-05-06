#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<vector<int>> f;
vector<vector<int>> cap;
int src=0,snk=1,ans=0;
void add(int u, int v, int cp) {
    f[u].push_back(v); f[v].push_back(u);
    cap[u][v] = cp;
}
bool bfs() {
    vector<int> p(f.size(), -1);
    vector<bool> iq(f.size());
    queue<int> q; q.push(src);
    iq[src] = true;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        for(int adj : f[r]) {
            if(iq[adj]) continue;
            if(cap[r][adj] > 0) q.push(adj), p[adj] = r, iq[adj] = true;
        }
    }
    if(p[snk] == -1) return false;
    int cur = snk;
    while(cur != src) {
        cap[p[cur]][cur]--;
        cap[cur][p[cur]]++;
        cur = p[cur];
    }
    ans++;
    return true;
}
int main() {
    int n, m, sz=0; cin>>n>>m;
    vector<ll> a(n);
    vector<vector<int>> p(n);
    vector<pair<int, int>> l(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        ll c = a[i];
        for (int j = 2; j*j <= c; ++j) while(a[i] % j == 0) a[i] /= j, p[i].push_back(j);
        if(a[i] > 1) p[i].push_back(a[i]);
        if(i == 0) l[i] = {2, 1 + p[i].size()};
        else l[i] = {l[i-1].second + 1, l[i-1].second + p[i].size()};
        sz += p[i].size();
    }
    f.resize(2 + sz);
    cap.resize(2 + sz, vector<int> (2 + sz));
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        if(u % 2) swap(u, v);
        for (int j = 0; j < p[u].size(); ++j) {
            for (int k = 0; k < p[v].size(); ++k) {
                if(p[u][j] == p[v][k]) {
                    add(l[u].first + j, l[v].first + k, 1);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            if(i % 2) add(l[i].first + j, snk, 1);
            else add(src, l[i].first + j, 1);
        }
    }
    while(true) if(!bfs()) break;
    cout << ans;
}
