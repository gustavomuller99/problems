#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int n; ll k;
vector<ll> h;
bool f(ll x) {
    ll ans = h[0] / x;
    ll r = h[0] % x;
    for (int i = 1; i < n; ++i) {
        ans = ans + ((h[i] + r) / x);
        if(h[i] + r < x) {
            r = h[i];
        } else {
            r = (h[i] + r) % x;
        }
    }
    return ans >= k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        h.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> h[i];
        ll l = 0, r = 1;
        while(f(r)) r *= 2;
        while(r > l + 1) {
            ll mid = l + (r - l) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l*k << "\n";
    }
}
