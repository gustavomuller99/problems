#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    ll ans = 0;
    for(int i = 0; i < min(n, m) && a[i] < b[i]; ++i) ans += b[i] - a[i];
    cout << ans << "\n";
}
