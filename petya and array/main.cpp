#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t, ans = 0; cin>>n>>t;
    vector<ll> a(n);
    set<ll> s; s.insert(0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i > 0) a[i] += a[i-1];
        auto it = s.upper_bound(a[i] - t);
        ans += distance(it, s.end());
        s.insert(a[i]);
    }
    cout << ans << "\n";
}
