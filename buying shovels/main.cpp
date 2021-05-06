#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin >> t;
    while(t--) {
        ll n,k; cin >> n >> k;
        if(k >= n) cout << "1" << endl;
        else {
            ll ans = n;
            for (ll i = 2; i*i <= n; ++i) {
                if(n%i==0) {
                    if(i <= k) ans = min(ans, n/i);
                    if(n/i <= k) ans = min(ans, i);
                }
            }
            cout << ans << endl;
        }
    }
}
