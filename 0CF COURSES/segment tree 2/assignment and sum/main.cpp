#include <bits/stdc++.h>
using namespace std;
#define ll  long long
vector<pair<ll, ll>> t;
void p(int n, int lx, int rx) {
    if(t[n].second != -1) {
        int mid = (rx + lx) / 2;
        t[2*n + 2].second = t[n].second;
        t[2*n + 2].first = (rx - mid)*t[2*n + 2].second;
        t[2*n + 1].second = t[n].second;
        t[2*n + 1].first = (mid - lx + 1)*t[2*n + 1].second;
        t[n].second = -1;
    }
}
void md(int l, int r, int lx, int rx, int n, ll v) {
    if(n < t.size()/2) p(n, lx, rx);
    if(lx >= l && rx <= r) {
        t[n].first = v * (rx - lx + 1);
        t[n].second = v;
        return;
    }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    md(l, r, lx, mid, 2*n + 1, v);
    md(l, r, mid+1, rx, 2*n + 2, v);
    t[n].first = t[2*n + 1].first + t[2*n + 2].first;
}
ll c(int l, int r, int lx, int rx, int n) {
    if(n < t.size()/2) p(n, lx, rx);
    if(lx >= l && rx <= r) return t[n].first;
    if(rx < l || lx > r) return 0;
    int mid = (lx + rx) / 2;
    ll rt = c(l, r, lx, mid, 2*n + 1) + c(l, r, mid+1, rx, 2*n + 2);
    return rt;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k, {0, -1});
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
