#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<pair<ll, ll>> t;
void a(int l, int r, int lx, int rx, int n, ll v) {
    if(lx >= l && rx <= r) {
        t[n].first += v;
        t[n].second += v;
        return;
    }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    a(l, r, lx, mid, 2*n + 1, v);
    a(l, r, mid+1, rx, 2*n + 2, v);
    t[n].first = min(t[2*n + 1].first, t[2*n + 2].first) + t[n].second;
}
ll g(int l, int r, int lx, int rx, int n) {
    if(lx >= l && rx <= r) return t[n].first;
    if(rx < l || lx > r) return LLONG_MAX;
    int mid = (lx + rx) / 2;
    ll rt = min(g(l, r, lx, mid, 2*n + 1), g(l, r, mid+1, rx, 2*n + 2));
    return rt + t[n].second;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            a(l, r - 1, 0, k/2, 0, v);
        } else {
            int l, r; cin >> l >> r;
            cout << g(l, r - 1, 0, k/2, 0) << "\n";
        }
    }
}
