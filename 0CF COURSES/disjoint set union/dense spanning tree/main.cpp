#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct e {ll w; int u, v;};
vector<int> d;
vector<e> t;
int n, m;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
bool f(e a, e b) { return a.w < b.w; }
pair<ll, int> mst(int i) {
    d = vector<int> (n + 1);
    for (int j = 0; j <= n; j++) d[j] = j;
    int v = 0;
    ll mx = LLONG_MIN;
    for (int j = i; j < t.size(); ++j) {
        int a = g(t[j].u), b = g(t[j].v);
        if(a != b) {
            v++;
            mx = max(mx, t[j].w);
            d[a] = b;
            if(v == n-1) break;
        }
    }
    return {mx, v};
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        t.push_back({w, u, v});
    }
    sort(t.begin(), t.end(), f);
    ll ans = LONG_MAX;
    bool ok = false;
    for (int i = 0; i < m; ++i) {
        ll min = t[i].w;
        auto rt = mst(i);
        if(rt.second < n - 1) break;
        ok = true;
        if(rt.first - min < ans) ans = rt.first - min;
    }
    if(ok) cout << "YES\n" << ans << "\n";
    else cout << "NO\n";
}
