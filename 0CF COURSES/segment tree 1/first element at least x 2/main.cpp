#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> t(1e6, 0);
int rec(ll v, int l, int lx, int rx, int n = 0) {
    if(t[n] < v || rx < l) return -1;
    if(lx == rx && lx >= l) return n;

    int mid = (lx + rx) / 2;
    int a = rec(v, l, lx, mid, 2*n + 1);
    if(a != -1) return a;
    else return rec(v, l, mid+1, rx, 2*n + 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k<n) {k*=2;} k*=2; k--;
    for (int i = k/2; i < k/2 + n; ++i) {
        cin >> t[i];
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        t[i] = max(t[i*2 + 1], t[i*2 + 2]);
    }
    while(m--) {
        int o; cin >> o;
        if(o == 2) {
            ll v; cin >> v;
            int l; cin >> l;
            int r = rec(v, l, 0, k/2);
            cout << (r == -1 ? -1 : r - k/2) << endl;
        } else {
            int i; cin >> i; i = k/2 + i;
            ll v; cin >> v;
            t[i] = v;
            while(i != 0) {
                i = i/2 - (i%2 == 0);
                t[i] = max(t[i*2 + 1], t[i*2 + 2]);
            }
        }
    }
}
