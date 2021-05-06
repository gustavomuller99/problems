#include <bits/stdc++.h>
using namespace std;
#define ll uint64_t
ll n;
int main() {
    cin>>n; bool f = true;
    set<ll> ans;
    for (ll i = 1; i <= n+1; i*=2) {
       ll l = 1, r = 2500000003;
       r=min(r,n/i+2);
       while(r > l + 1) {
           ll mid = l + (r-l)/2;
           if(mid*(i-1 + (mid-1)/2) > n) r = mid;
           else l = mid;
       }
       if(l*(i-1 + (l-1)/2) == n && l%2) {
           cout << l*i << "\n"; f = false;
        }
    }
    if(f) cout << -1;
}
