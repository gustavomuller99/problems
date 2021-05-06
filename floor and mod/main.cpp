#include <bits/stdc++.h>
using namespace std;
#define ll  long long
int main() {
    int t; cin>>t; while(t--) {
        ll x,y; cin>>x>>y;
        ll ans = 0;
        for (int i = 1; i*i <= x; ++i) ans += max(0LL, min(y, x/i - 1) - i);
        cout << ans << "\n";
    }
}
