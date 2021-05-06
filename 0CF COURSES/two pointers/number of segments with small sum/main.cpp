#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n,s,cs=0,ans=0; cin>>n>>s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int l = 0, r = 0;
    while(r < n) {
        cs += a[r];
        while(cs > s) cs -= a[l], l++;
        ans += (r-l+1);
        r++;
    }
    cout << ans;
}
