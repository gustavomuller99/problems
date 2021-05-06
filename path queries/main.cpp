#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> ans, d, sz, q;
vector<pair<int, pair<int, int>>> e;
map<int, pair<int, vector<int>>> mp;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m; cin>>n>>m;
    d.resize(n); sz.resize(n); ans.resize(m);
    unsigned long long r = 0;
    for (int i = 0; i < n; ++i) d[i] = i, sz[i] = 1;
    for (int i = 0; i < n-1; ++i) {
        int u,v,w; cin>>u>>v>>w; u--,v--;
        e.push_back({w, {u, v}});
    } sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        int w; cin>>w; q.push_back(w); mp[w].second.push_back(i);
    } sort(q.begin(), q.end());
    int index = 0;
    for(int w : q) {
        while(index != n-1 && e[index].first <= w) {
            int u = e[index].second.first, v = e[index].second.second;
            u = g(u), v = g(v);
            if(u != v) {
                r = r - (sz[u]*(sz[u]-1))/2 - (sz[v]*(sz[v]-1))/2 + ((sz[u]+sz[v])*(sz[u]+sz[v]-1))/2;
                d[u] = v;
                sz[v] += sz[u];
            }
            index++;
        }
        ans[mp[w].second[mp[w].first]] = r;
        mp[w].first++;
    }
    for(unsigned long long x : ans) cout << x << " ";
}
