#include <bits/stdc++.h>
using namespace std;
vector<int> d, c;
pair<int, int> g(int u) {
    if(u == d[u]) return {u, 0};
    else {
        auto rt = g(d[u]);
        d[u] = rt.first;
        c[u] += rt.second;
        return {d[u], c[u]};
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    d.resize(n); c.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        auto u1 = g(u), v1 = g(v);
        if(u1.first == v1.first) {
            if(u1.second % 2 == v1.second % 2) { cout << i+1; break; }
        } else {
            d[u1.first] = v1.first;
            c[u1.first] = c[v1.first] + 1;
        }
    }
}
