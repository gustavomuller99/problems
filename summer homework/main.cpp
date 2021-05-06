#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;
vector<pair<ll, int>> s;
vector<int> f;
void p(int i) {
    if(s[i].second == 1) {
        s[i].second = 0;
        s[2*i + 1].first += s[i].first; s[2*i + 1].second = 1;
        s[2*i + 2].first += s[i].first; s[2*i + 2].second = 1;
        s[i].first = 0;
    }
}
void as(int i, int lx, int rx, int v, int n = 0) {
    if(n < s.size() / 2) p(n);
    if(lx > i || rx < i) return;
    if(rx == lx) { s[n].first = v; return; }

    int mid = (lx + rx) / 2;
    as(i, lx, mid, v, 2*n + 1);
    as(i, mid+1, rx, v, 2*n + 2);
}
ll calc(int l, int r, int lx, int rx, int n = 0) {
    if(n < s.size() / 2) p(n);
    if(lx > r || rx < l) return 0;
    if(lx == rx) {
        return (s[n].first * f[lx - l]) % MOD;
    }
    int mid = (lx + rx) / 2;
    return (calc(l, r, lx, mid, 2*n + 1) + calc(l, r, mid+1, rx, 2*n + 2)) % MOD;
}
void md(int l, int r, int lx, int rx, int d, int n = 0) {
    if(n < s.size() / 2) p(n);
    if(lx > r || rx < l) return;
    if(lx >= l && rx <= r) {
        s[n].first += d;
        s[n].second = 1;
        return;
    }
    int mid = (lx + rx) / 2;
    md(l, r, lx, mid, d, 2*n + 1);
    md(l, r, mid+1, rx, d, 2*n + 2);
}
int n, m, k = 1;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    while(k < n) k *= 2;
    k *= 2; k--;
    s.resize(k); f.resize(n);
    for (int i = 0; i <= k/2; ++i) s[k/2 + i].first = 1;
    for (int i = 0; i < n; ++i) cin >> s[k/2 + i].first;
    f[0] = f[1] = 1;
    for (int i = 2; i < n; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    while(m--) {
        int t; cin >> t;
        if(t == 1) {
            int x, v; cin >> x >> v; x--;
            as(x, 0, k/2, v);
        } else if(t == 2) {
            int l, r; cin >> l >> r; l--, r--;
            cout << calc(l, r, 0, k/2) << "\n";
        } else {
            int l, r, d; cin >> l >> r >> d;
            l--, r--;
            md(l, r, 0, k/2, d);
        }
    }
}
