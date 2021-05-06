#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int n,k;
vector<ll> a;
bool f(ll mx) {
    ll sum = 0, d = 1;
    for (int i = 0; i < n; ++i) {
        if(a[i] > mx) return false;
        if(sum + a[i] > mx) d++, sum = 0;
        sum += a[i];
    }
    return d <= k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        cin>>n>>k;
        a = vector<ll>(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) cin>>a[i], sum += a[i];
        ll l = -1, r = sum+3;
        while(l + 1 < r) {
            ll mid = (l+r) / 2;
            if(f(mid)) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}
