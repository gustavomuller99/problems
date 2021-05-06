#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<vector<int>> t;
vector<int> st;
vector<bool> pt;
ll n, x, y;
int dfs(int i, int f) {
    st[i] = 1;
    if(i == y) pt[i] = true;
    for(int adj : t[i]) {
        if(adj == f) continue;
        st[i] += dfs(adj, i);
        pt[i] = pt[i] || pt[adj];
    }
    return st[i];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> x >> y; x--, y--;
    t.resize(n); st.resize(n); pt.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(x,x);
    ll a = n*(n-1), p;
    for(int adj : t[x]) { if(pt[adj]) p = st[adj]; }
    cout << a - (st[y]*(n - p));
}
