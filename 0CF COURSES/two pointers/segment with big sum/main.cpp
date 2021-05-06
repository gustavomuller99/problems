#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n,s,cs=0; cin>>n>>s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int ans=INT_MAX,l=0,r=0;
    while(r < n) {
        cs += a[r];
        while(cs - a[l] >= s) cs -= a[l], l++;
        if(cs >= s) ans = min(ans, r-l+1);
        r++;
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}
