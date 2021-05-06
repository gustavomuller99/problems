#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<pair<ll, ll>> t;
void md(int l, int r, int lx, int rx, int n, ll v) {
    if(lx >= l && rx <= r) {
        t[n].first *= v; t[n].first %= MOD;
        t[n].second *= v; t[n].second %= MOD;
        return;
    }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    md(l, r, lx, mid, 2*n + 1, v);
    md(l, r, mid+1, rx, 2*n + 2, v);
    t[n].first = ((t[2*n + 1].first + t[2*n + 2].first) * t[n].second) % MOD;
}
ll c(int l, int r, int lx, int rx, int n) {
    if(lx >= l && rx <= r) return t[n].first;
    if(rx < l || lx > r) return 0;
    int mid = (lx + rx) / 2;
    ll rt = (c(l, r, lx, mid, 2*n + 1) + c(l, r, mid+1, rx, 2*n + 2)) % MOD;
    return (rt * t[n].second) % MOD;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k, {1, 1});
    for(int i = k/2 - 1; i >= 0; --i) t[i].first = t[2*i + 1].first + t[2*i + 2].first;
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            md(l, r - 1, 0, k/2, 0, v);
        } else {
            int l, r; cin >> l >> r;
            cout << c(l, r - 1, 0, k/2, 0) << "\n";
        }
    }
}
