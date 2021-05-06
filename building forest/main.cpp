#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<pair<int, ll>> d;
pair<int, ll> g(int u) {
    if(d[u].first == u) return {u, 0};
    auto r = g(d[u].first);
    d[u] = {r.first, r.second + d[u].second};
    return {r.first, d[u].second};
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    d.resize(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) d[i] = {i,0};
    for (int i = 0; i < n; ++i) {
        int k; cin>>k;
        for (int j = 0; j < k; ++j) {
            int v; ll x; cin>>v>>x; v--;
            pair<int, ll> r = g(v);
            d[r.first] = {i, (r.second + x) % mod};
            ans = (ans + d[r.first].second) % mod;
        }
    }
    cout << (ans + mod) % mod << "\n";
}
