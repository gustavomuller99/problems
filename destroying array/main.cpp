#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a, p;
vector<int> d1, d2, r;
int g1(int u) { return d1[u] = (d1[u] == u ? u : g1(d1[u])); }
int g2(int u) { return d2[u] = (d2[u] == u ? u : g2(d2[u])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    a.resize(n); r.resize(n); d1.resize(n + 2); d2.resize(n + 2), p.resize(n + 1);
    for (int i = 0; i < n + 2; ++i) d1[i] = d2[i] = i;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        a[i] = k;
    }
    p[0] = 0;
    for (int i = 1; i <= n; ++i) { p[i] = a[i-1] + p[i-1]; }
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        r[i] = k;
    }
    vector<ll> ans; ans.push_back(0);
    ll mx = 0;
    for (auto i = r.rbegin(); i < r.rend(); ++i) {
        int c = *i;
        d1[c] = d1[c-1];
        d2[c] = d2[c+1];
        int u = g1(c), v = g2(c);
        u++, v--;
        ll sum = p[v] - p[u-1];
        mx = max(mx, sum);
        ans.push_back(mx);
    }
    for(auto i = ans.rbegin()+1; i < ans.rend(); ++i) cout << *i << "\n";
}
