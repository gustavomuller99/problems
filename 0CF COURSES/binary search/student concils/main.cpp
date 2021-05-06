#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
int k;
bool f(ll x) {
    ll s = x*k;
    for(ll p : a) {
        s -= min(x, p);
    }
    return s <= 0;
}
int main() {
    int n; cin >> k >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = 1;
    while(f(r)) r *= 2;
    while(r > l + 1) {
        ll mid = (r + l) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}
