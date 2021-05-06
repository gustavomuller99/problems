#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<ll, ll> m;
ll rc(ll n, ll lx, ll rx, ll l, ll r) {
    if(rx < l || lx > r) return 0;
    if(n < 2) return n;
    if(lx >= l && rx <= r && m[n] != 0) return m[n];
    ll rt = 0;
    ll mid = (lx + rx) / 2;
    rt += rc(n/2, lx, mid-1, l, r);
    rt += rc(n%2, mid, mid, l, r);
    rt += rc(n/2, mid+1, rx, l, r);
    if(lx >= l && rx <= r) m[n] = rt;
    return rt;
}
ll sz(ll n) {
    if(n<2) return 1;
    return 1 + 2*sz(n/2);
}
ll n, l, r;
int main() {
    cin >> n >> l >> r;
    ll rx = sz(n);
    cout << rc(n, 1, rx, l, r);
}
