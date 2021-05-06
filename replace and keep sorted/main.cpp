#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n, q, k; cin>>n>>q>>k;
    vector<ll> a(n), d(n+1);
    for (int i = 0; i < n; ++i) cin>>a[i];
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        ll u = (i < n-1 ? a[i+1] : k+1), l = (i > 0 ? a[i-1] : 0);
        d[i+1] = u-l-2;
        d[i+1] += d[i];
    }
    for (int i = 0; i < q; ++i) {
        int l, r; cin>>l>>r;
        ll ans = d[r] - d[l-1];
        if(l > 1) ans += a[l-2];
        if(r < n) ans += k - a[r] + 1;
        cout << ans << "\n";
    }
}
