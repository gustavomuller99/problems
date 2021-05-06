#include <bits/stdc++.h>
using namespace std;
#define ll  long long
struct nd { ll seg, pre, suf, sum; };
vector<pair<nd, ll>> t;
void p(int n, int lx, int rx) {
    if(t[n].second != LLONG_MAX) {
        nd p; int mid = (lx + rx) / 2;
        p.sum = t[n].second * (mid - lx + 1);
        if(t[n].second > 0) p.seg = p.pre = p.suf = p.sum;
        else p.seg = p.pre = p.suf = 0;
        t[2*n + 1].first = t[2*n + 2].first = p;
        t[2*n + 1].second = t[2*n + 2].second = t[n].second;
        t[n].second = LLONG_MAX;
    }
}
void md(int l, int r, int lx, int rx, int n, ll v) {
    if(lx >= l && rx <= r) {
        t[n].first.sum = v * (rx - lx + 1);
        if(v > 0) t[n].first.seg = t[n].first.pre = t[n].first.suf = t[n].first.sum;
        else t[n].first.seg = t[n].first.pre = t[n].first.suf = 0;
        t[n].second = v;
        return;
    }
    if(n < t.size()/2) p(n, lx, rx);
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    md(l, r, lx, mid, 2*n + 1, v);
    md(l, r, mid+1, rx, 2*n + 2, v);
    t[n].first.sum = t[2*n + 1].first.sum + t[2*n + 2].first.sum;
    t[n].first.pre = max(t[2*n + 1].first.pre, t[2*n + 1].first.sum + t[2*n + 2].first.pre);
    t[n].first.suf = max(t[2*n + 2].first.suf, t[2*n + 1].first.suf + t[2*n + 2].first.sum);
    t[n].first.seg = max(t[2*n + 1].first.seg, max(t[2*n + 2].first.seg, t[2*n + 1].first.suf + t[2*n + 2].first.pre));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k, {{0, 0, 0, 0}, LLONG_MAX});
    while(m--) {
        int l, r; ll v; cin >> l >> r >> v;
        md(l, r - 1, 0, k/2, 0, v);
        /*for(auto x : t) {
            cout << x.first.seg << " " << x.first.pre << " " << x.first.suf << " " << x.first.sum << " " << x.second << "\n";
        } cout << "\n";*/
        cout << max(t[0].first.sum, max(t[0].first.seg, max(t[0].first.pre, t[0].first.suf))) << "\n";
    }
}
