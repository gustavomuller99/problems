#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> s;
ll l, r;
ll rec(int lx, int rx, int i) {
    if(lx >= l && rx < r) return s[i];
    if(rx < l || lx >= r) return LLONG_MAX;

    int mid = (lx + rx) / 2;
    return min(rec(lx, mid, i*2 + 1), rec(mid+1, rx, i*2 + 2));
}
int main() {
    ios::sync_with_stdio(false);
    int n, m, k = 1; cin >> n >> m;

    while(k < n) {
        k*=2;
    } k*=2; k--;

    s.resize(k, LLONG_MAX);

    for (int i = k/2; i < k/2 + n; ++i) {
        cin >> s[i];
    }

    for (int i = k/2 - 1; i >= 0; --i) {
        s[i] = min(s[i*2 + 1], s[i*2 + 2]);
    }

    while(m--) {
        int o; cin >> o >> l >> r;
        if(o == 1) {
            int i = k/2 + (int) l;
            ll v = r; s[i] = v;
            while(i != 0) {
                i = i/2 - (i%2 == 0);
                s[i] = min(s[i*2 + 1], s[i*2 + 2]);
            }
        } else {
            cout << rec(0, k/2, 0) << endl;
        }
    }
}
