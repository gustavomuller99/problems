#include <bits/stdc++.h>
using namespace std;
vector<int> d, sz;
int g(int u) { return d[u] == u ? u : g(d[u]); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    d.resize(n); sz.resize(n);
    stack<int> s;
    vector<int> p;
    int cc = n;
    for (int i = 0; i < n; ++i) d[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        string o; cin>>o;
        if(o[0] == 'p') {
            s.push(p.size());
        }
        else if(o[0] == 'r') {
            int stop = s.top(); s.pop();
            while(p.size() != stop) {
                int x = p.back(); p.pop_back();
                int v = g(x);
                sz[v] -= sz[x];
                d[x] = x;
                cc++;
            }
            cout << cc << "\n";
        }
        else if(o[0] == 'u') {
            int u,v; cin>>u>>v; u--,v--;
            u = g(u), v = g(v);
            if(u != v) {
                cc--;
                if(sz[u] > sz[v]) swap(u, v);
                d[u] = v; p.push_back(u);
                sz[v] += sz[u];
            }
            cout << cc << "\n";
        }
    }
}
