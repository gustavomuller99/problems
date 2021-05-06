#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<int> d;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,a,b,c; cin>>n>>m>>a>>b>>c; a--,b--;
    ll ans;
    d.resize(n);
    vector<pair<ll, pair<int, int>>> e(m-1);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < m-1; ++i) {
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;
        e[i].second.first--, e[i].second.second--;
    } sort(e.begin(), e.end());
    for (int i = 0; i < m-1; ++i) {
        int u = g(e[i].second.first), v = g(e[i].second.second);
        if(u != v) d[u] = v;
        if(g(a) == g(b)) { ans = e[i].first; break; }
    }
    if(g(a) != g(b)) ans = 1e9;
    cout << min(ans, (ll) 1e9);
}
