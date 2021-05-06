#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx >= l && rx <= r) return t[n];
    if(rx < l || lx > r) return 0;

    int mid = (lx + rx) / 2;
    return rec(l, r, lx, mid, 2*n + 1) + rec(l, r, mid + 1, rx, 2*n + 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1;
    cin >> n;
    while (k < n) k *= 2;
    k *= 2;
    k--;
    t.resize(k);
    for (int i = k/2; i < k/2 + n; ++i) {
        cin >> t[i];
    }
    for (int i = k/4; i < k/2; ++i) {
        t[i] = t[i*2 + 1] - t[i*2 + 2];
    }
    for (int i = k/4 - 1; i >= 0; --i) {
        t[i] = t[i*2 + 1] + t[i*2 + 2];
    }
    int m; cin >> m;
    while (m--) {
        int op; cin >> op;
        if(op) {
            int l, r; cin >> l >> r;
            l--; r--;
            if((k/2 + l)%2 == 0) {
                int ans = rec(l+1, r, 0, k/2);
                cout << t[k/2 + l] - ans << "\n";
            } else {
                cout << rec(l, r, 0, k/2) << "\n";
            }
        } else {
            int i, v; cin >> i >> v;
            i--;
            int index = k/2 + i;
            t[index] = v; index = index/2 - (index%2 == 0);
            t[index] = t[index*2 + 1] - t[index*2 + 2];
            while(index != 0) {
                index = index/2 - (index%2 == 0);
                t[index] = t[index*2 + 1] + t[index*2 + 2];
            }
        }
    }
}
