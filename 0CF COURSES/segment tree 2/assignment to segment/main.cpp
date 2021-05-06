#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> t;
void p(int n) {
    if(t[n] != -1) {
        t[2 * n + 1] = t[n];
        t[2 * n + 2] = t[n];
        t[n] = -1;
    }
}
void a(int l, int r, int lx, int rx, int n, ll v) {
    if(n < t.size() / 2) p(n);
    if(lx >= l && rx <= r) { t[n] = v; return; }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    a(l, r, lx, mid, 2*n + 1, v);
    a(l, r, mid+1, rx, 2*n + 2, v);
}
int g(int i, int lx, int rx, int n = 0) {
    if(n < t.size() / 2) p(n);
    else return t[n];
    int mid = (lx + rx) / 2;
    if(i > mid) return g(i, mid+1, rx, 2*n + 2);
    else return g(i, lx, mid, 2*n + 1);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k, -1);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            a(l, r - 1, 0, k/2, 0, v);
        } else {
            int index; cin >> index;
            ll r = g(index, 0, k/2);
            cout << (r == -1 ? 0 : r) << "\n";
        }
    }
}
