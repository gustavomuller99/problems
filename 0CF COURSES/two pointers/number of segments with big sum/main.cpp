#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n,s,cs=0,ans=0; cin>>n>>s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int r = 0, l = 0;
    while(r < n) {
        cs += a[r];
        while(cs - a[l] >= s) cs -= a[l], l++;
        if(cs >= s) ans += (l+1);
        r++;
    }
    cout << ans;
}
