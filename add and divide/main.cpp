#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll a,b; cin>>a>>b;
        ll ans = INT_MAX;
        if(a < b) { cout << "1\n"; continue; }
        if(b != 1) {
            ll mv = 0, p = a;
            while(p > 0) p /= b, mv++;
            ans = min(ans, mv);
        }
        for (ll i = b+1; i*i <= a+1; ++i) {
            ll mv = (i-b); ll p = a;
            while(p > 0) p /= i, mv++;
            ans = min(ans, mv);
        }
        ans = min(ans, a+2-b);
        cout << ans << "\n";
    }
}
