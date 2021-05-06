#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> t;
int rec(int l, int r, int lx, int rx, ll p, int n = 0) {
    if(rx < l || lx > r) return 0;
    if(n >= t.size() / 2) {
        if(t[n] <= p) {
            t[n] = LONG_LONG_MAX;
            return 1;
        } else return 0;
    } else {
        if(t[n] > p) return 0;
        int mid = (lx + rx) / 2;
        return rec(l, r, lx, mid, p, 2*n + 1) + rec(l, r, mid+1, rx, p, 2*n + 2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, k = 1; cin >> n >> q;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k, LONG_LONG_MAX);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int i; ll h;
            cin >> i >> h;
            i = k/2 + i;
            t[i] = h;
            while(i != 0) {
                i = i/2 - (i%2 == 0);
                t[i] = min(t[i*2 + 1], t[i*2 + 2]);
            }
        } else {
            int l, r; ll p;
            cin >> l >> r >> p;
            r--;
            cout << rec(l, r, 0, k/2, p) << "\n";
        }
    }
}
