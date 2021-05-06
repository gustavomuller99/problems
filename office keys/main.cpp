#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,k,p; cin>>n>>k>>p;
    vector<ll> pos(n), a(k);
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) cin>>pos[i];
    for (int i = 0; i < k; ++i) cin>>a[i];
    sort(a.begin(), a.end()); sort(pos.begin(), pos.end());
    for (int i = n-1; i < k; ++i) {
        ll temp = 0;
        for (int j = 0; j < n; ++j) {
            temp = max(temp, abs(pos[j] - a[i+j-(n-1)]) + abs(a[i+j-(n-1)] - p));
        }
        if(temp < ans) ans = temp;
    }
    cout << ans;
}
