#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> t;
ll rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx >= l && rx <= r) return t[n];
    if(rx < l || lx > r) return 0;

    int mid = (lx + rx) / 2;
    return rec(l, r, lx, mid, 2*n + 1) + rec(l, r, mid + 1, rx, 2*n + 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1, m;
    cin >> n >> m;
    while (k < 2 * n) k *= 2;
    k *= 2;
    k--;
    t.resize(k);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; ll v;
            cin >> l >> r >> v;
            int index = k/2 + l;
            t[index] += v;
            while(index != 0) {
                index = index/2 - (index%2 == 0);
                t[index] += v;
            }
            index = k/2 + r;
            t[index] -= v;
            while(index != 0) {
                index = index/2 - (index%2 == 0);
                t[index] -= v;
            }
        } else {
            int r; cin >> r;
            cout << rec(0, r, 0, k/2) << "\n";
        }
    }
}