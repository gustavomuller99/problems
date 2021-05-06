#include <bits/stdc++.h>
using namespace std;
int g(int u, vector<int>&d) { return d[u] = d[u] == u ? u : g(d[u], d); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k; cin>>n>>m;
    vector<pair<int, int>> e(m);
    vector<vector<int>> p(m+1, vector<int>(n)), s(m+1, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        e[i] = {u,v};
    }
    for (int i = 0; i < n; ++i) p[0][i] = s[m][i] = i;
    for (int i = 0; i < m; ++i) {
        p[i+1] = p[i];
        int u = g(e[i].first, p[i+1]), v = g(e[i].second, p[i+1]);
        if(u != v) p[i+1][u] = v;
    }
    for (int i = m-1; i >= 0; --i) {
        s[i] = s[i+1];
        int u = g(e[i].first, s[i]), v = g(e[i].second, s[i]);
        if(u != v) s[i][u] = v;
    }
    cin>>k;
    vector<int> d(n);
    for (int i = 0; i < k; ++i) {
        int l,r,cc=0; cin>>l>>r;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) d[j] = p[l-1][j];
        for (int j = 0; j < n; ++j) d[g(j, d)] = g(s[r][j], d);
        for (int j = 0; j < n; ++j) if(d[j] == j) cc++;
        cout << cc << "\n";
    }
}
