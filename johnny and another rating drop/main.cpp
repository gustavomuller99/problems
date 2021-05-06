#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll ans = 0;
        for(ll i = 0; n >> i != 0; i++) {
            ll k = 1ULL << i;
            ans += n / k;
        }
        cout << ans << "\n";
    }
}
