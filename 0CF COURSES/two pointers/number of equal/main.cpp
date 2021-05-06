#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,m; cin>>n>>m;
    ll ans = 0;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int j = 0; j < m; ++j) cin>>b[j];
    int l = 0, r = 0, l1 = 0;
    while(r < b.size()) {
        if(!r || b[r] != b[r-1]) {
            while(l < a.size() && a[l] < b[r]) l++;
            l1 = l;
            while(l < a.size() && a[l] == b[r]) l++;
        }
        if(l1 < a.size() && a[l1] == b[r]) ans += (l-l1);
        r++;
    }
    cout << ans << "\n";
}
