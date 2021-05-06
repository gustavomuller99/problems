#include <bits/stdc++.h>
using namespace std;
struct nd {
    int f[41] = {0};
    long long cnt = 0;
};
vector<nd> t;
nd combine(nd a, nd b) {
    nd p;
    p.cnt = a.cnt + b.cnt;
    for (int i = 1; i < 41; ++i) {
        p.f[i] = a.f[i] + b.f[i];
        for (int j = i+1; j < 41; ++j) {
            p.cnt += b.f[i] * a.f[j];
        }
    }
    return p;
}
nd rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx >= l && rx <= r) return t[n];
    if(rx < l || lx > r) {nd id; return id;}

    int mid = (lx + rx) / 2;
    return combine(rec(l, r, lx, mid, 2*n + 1), rec(l, r, mid+1, rx, 2*n + 2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, k = 1; cin >> n >> q;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k);
    for (int i = k/2; i < k/2 + n; ++i) {
        int p; cin >> p;
        nd node;
        node.f[p]++;
        t[i] = node;
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        t[i] = combine(t[i*2 + 1], t[i*2 + 2]);
    }
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << rec(l, r, 0, k/2).cnt << "\n";
        } else {
            int index, v; cin >> index >> v;
            index = index + k/2 - 1;
            nd node;
            node.cnt = 0;
            node.f[v]++;
            t[index] = node;
            while(index != 0) {
                index = index/2 - (index%2 == 0);
                t[index] = combine(t[index*2 + 1], t[index*2 + 2]);
            }
        }
    }
}

