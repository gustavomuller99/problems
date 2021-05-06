#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> t;
void rec(int l, int r, int lx, int rx, int n, ll v) {
    if(lx >= l && rx <= r) { t[n] += v; return; }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    rec(l, r, lx, mid, 2*n + 1, v);
    rec(l, r, mid+1, rx, 2*n + 2, v);
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
            rec(l, r - 1, 0, k/2, 0, v);
        } else {
            int index; cin >> index;
            index = index + k/2;
            ll s = t[index];
            while(index != 0) {
                index = index/2 - (index % 2 == 0);
                s += t[index];
            }
            cout << s << "\n";
        }
    }
}
