#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<int> d;
int g(int u) { return d[u] = (d[u] == u ? u : g(d[u])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k=0,cnt=0; cin>>n>>m;
    ll ans = 0, mn = LLONG_MAX;
    vector<ll> a(n); d.resize(n);
    set<pair<ll, pair<int,int>>> p;
    for (int i = 0; i < n; ++i) d[i]=i;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(mn > a[i]) k = i, mn = a[i];
    }
    for (int i = 0; i < n; ++i) {
        if(i == k) continue;
        p.insert({a[i] + mn, {i, k}});
    }
    for (int i = 0; i < m; ++i) {
        int x, y; ll w; cin >> x >> y >> w; x--, y--;
        p.insert({w, {x,y}});
    }
    for(auto x : p) {
        int u = g(x.second.first), v = g(x.second.second);
        ll c = x.first;
        if(u != v) {
            cnt++; ans += c;
            d[u] = v;
        }
        if(cnt == n-1) break;
    }
    cout << ans;
}
