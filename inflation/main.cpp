#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll n, k, s=0, ans = 0; cin>>n>>k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i], s+=a[i];
        for (int i = n-1; i > 0; --i) {
            s -= a[i];
            ll x = 100*a[i];
            ll l = 0, r = 1e18;
            while(l + 1 < r) {
                ll mid = (l+r)/2;
                if(mid*k >= x) r = mid;
                else l = mid;
            }
            if(r > s) ans += r-s;
            s = max(s, r);
        }
        cout << ans << "\n";
    }
}
